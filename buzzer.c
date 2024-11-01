/*
 * buzzer.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Yoann Hervagault
 */

#include "buzzer.h"
#include "scores/scores.h"

BUZZER_Result buzzer_vsetTimeBaseFreq(ts_buzzer* buz,uint16_t bpm);
int buzzer_ipower(uint8_t x, uint8_t n);
void buzzerMNG_start();
void buzzerMNG_stop();
uint32_t buzzer_PCLKxTIM(TIM_HandleTypeDef* ftim);
BUZZER_Result buzzer_eVerifyTimersConfig(TIM_HandleTypeDef* fhtimeBaseTim, TIM_HandleTypeDef* fhfrequencyTim);


float fNotesFrequencies[noteNB]=
{
	65.41, //C1
	69.30,
	73.42,
	77.78,
	82.41,
	87.31,
	92.50,
	98,
	103.83,
	110,
	116.54,
	123.47, //B1
	0,
};

BUZZER_Result buzzer_eInit(ts_buzzer* buz, TIM_HandleTypeDef* fhtim, TIM_HandleTypeDef* fhtim2, uint32_t u32Channel)
{
	BUZZER_Result eResult = BUZZER_OK;
	if(buz==0 || fhtim==0 || fhtim2==0)
	{
		eResult = BUZZER_PARAMETER_ERROR;
	}
	else
	{
		eResult = buzzer_eVerifyTimersConfig(fhtim2, fhtim);
		if(eResult == BUZZER_OK)
		{
			buz->freqTimer = fhtim;
			buz->timeBaseTimer = fhtim2;
			buz->u32FreqChannel = u32Channel;
			buz->u8BuzzerTbFlag=0;
		}
	}
	return eResult;
}

BUZZER_Result buzzer_eStart(ts_buzzer* buz)
{
	BUZZER_Result eResult = BUZZER_OK;
	if(HAL_TIM_PWM_Start(buz->freqTimer, buz->u32FreqChannel)==HAL_OK)
	{
		eResult = BUZZER_OK;
	}
	else
	{
		eResult = BUZZER_INTERNAL_ERROR;
	}
	return eResult;
}

BUZZER_Result buzzer_eStop(ts_buzzer* buz)
{
	BUZZER_Result eResult = BUZZER_OK;
	if(HAL_TIM_PWM_Stop(buz->freqTimer, buz->u32FreqChannel)==HAL_OK)
	{
		eResult = BUZZER_OK;
	}
	else
	{
		eResult = BUZZER_INTERNAL_ERROR;
	}
	return eResult;
}

BUZZER_Result buzzer_eSetfrequency(ts_buzzer* buz,float freq)
{
	BUZZER_Result eResult = BUZZER_OK;
	if(freq == 0)
	{
		buz->freqTimer->Instance->ARR = (uint32_t)1000-1;
		buz->freqTimer->Instance->CCR1 = (uint32_t)0;
		buz->freqTimer->Instance->CR1 &= ~TIM_CR1_UDIS;
	}
	else
	{
		uint16_t u16period = (uint16_t)(1000000/freq);

		//TODO: tester utiliser fonctions _HAL
		buz->freqTimer->Instance->ARR = (uint32_t)u16period-1;
		buz->freqTimer->Instance->CCR1 = (uint32_t)u16period/6;
		buz->freqTimer->Instance->CR1 &= ~TIM_CR1_UDIS;
	}
	return eResult;
}

BUZZER_Result buzzer_ePlaySong(ts_buzzer* buz, buzzernote* partition, uint8_t baseoctave, uint32_t length, uint16_t bpm)
{
	BUZZER_Result eResult = BUZZER_OK;
	buzzer_vsetTimeBaseFreq(buz, bpm);
	uint32_t u32Period = 1000*60/bpm;
	if (HAL_TIM_Base_Start_IT(buz->timeBaseTimer) != HAL_OK)
	{
	  eResult = BUZZER_INTERNAL_ERROR;
	}
	else
	{
		buzzer_eStart(buz);
		int i=0;
		int cpt_tempo=0;
		uint8_t u8imp=0;
		while(i<length)
		{
			if(u8imp==0)
			{
				buzzer_eSetfrequency(buz,none);
				HAL_Delay(5);
				u8imp=1;
			}
			buzzer_eSetfrequency(buz,fNotesFrequencies[partition[i].basefreq]*buzzer_ipower(2U,partition[i].octave+baseoctave));
			if(partition[i].isternary==1)
			{
				HAL_Delay((uint32_t)(0.66*u32Period* partition[i].tempo));
				buz->u8BuzzerTbFlag=0;
				cpt_tempo = 0;
				u8imp=0;
				i++;
			}
			else if(buz->u8BuzzerTbFlag==1)
			{
				buz->u8BuzzerTbFlag=0;
				cpt_tempo++;
				if(cpt_tempo == partition[i].tempo)
				{
					cpt_tempo=0;
					u8imp=0;
					if(partition[i].repeat[1]>0)
					{
						partition[i].repeat[1]--;
						i=partition[i].repeat[0];
					}
					else
					{
						i++;
					}

				}
			}
		}
		buzzer_eStop(buz);
		HAL_TIM_Base_Stop_IT(buz->timeBaseTimer);
	}
	return eResult;
}

BUZZER_Result buzzer_vsetTimeBaseFreq(ts_buzzer* buz,uint16_t bpm)
{
	BUZZER_Result eResult = BUZZER_OK;
	uint32_t u32tbperiod = 1000*60/bpm;//target time base period in ms
	uint32_t arr = u32tbperiod*10; //time base timer frequency is 10kHz (10 samples in 1ms)
	__HAL_TIM_SET_AUTORELOAD(buz->timeBaseTimer, arr);
	return eResult;
}

int buzzer_ipower(uint8_t x, uint8_t n)
{
	uint8_t result = x;
	if(x==0)
		return 0;
	else
	{
		if(n==0)
			return 1;
		else
		{
			uint8_t cpt=1;
			while(cpt<n)
			{
				result = result*x;
				cpt++;
			}
			return result;
		}
	}
}

void buzzer_vDemoTask(ts_buzzer* buz)
{
  /* USER CODE BEGIN StartJukeboxTask */
  /* Infinite loop */
	for(int i=0;i<theme_nb;i++)
	{
#ifdef BUZZER_ZELDA
		  if(i == zelda_theme)
		  {
			  buzzer_ePlaySong(buz, zelda,3,152,500);
		  }
#endif
#ifdef BUZZER_MARIO
		  if(i == mario_theme)
		  {
			  buzzer_ePlaySong(buz, mario,3,127, 360);
		  }
#endif
#ifdef BUZZER_POKEMON
		  if(i == pokemon_battletheme)
		  {
			  buzzer_ePlaySong(buz, pokemon,2,451, 180*4);
		  }
#endif
		  HAL_Delay(1000);
	}
  /* USER CODE END StartJukeboxTask */
}


BUZZER_Result buzzer_eVerifyTimersConfig(TIM_HandleTypeDef* fhtimeBaseTim, TIM_HandleTypeDef* fhfrequencyTim)
{

	BUZZER_Result eResult = BUZZER_OK;
	if((fhtimeBaseTim->Instance->PSC +1)*1000000 != servo_PCLKxTIM(fhtimeBaseTim)*100)//force timer resolution to 100µs (10kHz)
	{
		eResult = BUZZER_PARAMETER_ERROR;
	}
	if(eResult == BUZZER_OK)
	{
		if((fhfrequencyTim->Instance->PSC +1)*1000000 != servo_PCLKxTIM(fhfrequencyTim))//force pwm resolution to 1µs
		{
			eResult = BUZZER_PARAMETER_ERROR;
		}
	}
	return eResult;
}

uint32_t buzzer_PCLKxTIM(TIM_HandleTypeDef* ftim)
{
  /* Get PCLK1 frequency */
  uint32_t pclkx;
  if(ftim->Instance == TIM3 || ftim->Instance == TIM4 || ftim->Instance == TIM5 || ftim->Instance == TIM6 || ftim->Instance == TIM7)
  {
	  pclkx = HAL_RCC_GetPCLK1Freq();
	  if((RCC->CFGR & RCC_CFGR_PPRE1) != 0)
	  {
		  pclkx *=2;
	  }
  }
  else
  {
	  pclkx = HAL_RCC_GetPCLK2Freq();
	  if((RCC->CFGR & RCC_CFGR_PPRE2) != 0)
	  {
		  pclkx *=2;
	  }
  }
  return pclkx;
}
