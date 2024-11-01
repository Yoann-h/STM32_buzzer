/*
 * buzzer.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Yoann Hervagault
 */
//A buzzer object needs 2 timers to be used: one for the time base, and one to generate the notes.
//the frequency timer prescaler has to be configured so that the time quanta is 1 microsecond. Other parameters haven't been tested.
//The library time base is set from timer interrupt
//to use the library, you have to update the u8BuzzerTbFlag (set to 1) value in HAL_TIM_PeriodElapsedCallback function.
//for example, define in main:
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//  /* USER CODE BEGIN Callback 0 */
//  if (htim == buzzer.timeBaseTimer )
//  {
//	  buzzer.u8BuzzerTbFlag = 1;
//  }
//  /* USER CODE END Callback 0 */
//  /* USER CODE BEGIN Callback 1 */
//
//  /* USER CODE END Callback 1 */
//}


#ifndef YHLIB_BUZZER_BUZZER_H_
#define YHLIB_BUZZER_BUZZER_H_

#include "buzzer_cfg.h"

typedef enum {
	BUZZER_OK, BUZZER_PARAMETER_ERROR, BUZZER_INTERNAL_ERROR, BUZZER_RESULTNB
} BUZZER_Result;

typedef enum{

	C1 = 0,
	Cd1,
	D1,
	Dd1,
	E1,
	F1,
	Fd1,
	G1,
	Gd1,
	A1,
	Ad1,
	B1,
	none,
	noteNB
}buzzerfreq;

typedef struct{
	buzzerfreq basefreq;
	uint8_t octave;
	uint8_t tempo;
	uint8_t isternary;
	uint8_t repeat[2];
}buzzernote;

typedef struct {
	TIM_HandleTypeDef* freqTimer;
	TIM_HandleTypeDef* timeBaseTimer;
	uint32_t u32FreqChannel;
	uint8_t u8BuzzerTbFlag;
}ts_buzzer;

BUZZER_Result buzzer_eInit(ts_buzzer* buz, TIM_HandleTypeDef* fhtim, TIM_HandleTypeDef* fhtim2, uint32_t u32Channel);
BUZZER_Result buzzer_eStart(ts_buzzer* buz);
BUZZER_Result buzzer_eStop(ts_buzzer* buz);
BUZZER_Result buzzer_eSetfrequency(ts_buzzer* buz,float freq);
BUZZER_Result buzzer_ePlaySong(ts_buzzer* buz, buzzernote* partition, uint8_t baseoctave, uint32_t length, uint16_t bpm);
void buzzer_vDemoTask(ts_buzzer* buz);

#endif /* YHLIB_BUZZER_BUZZER_H_ */
