/*
 * score_mario.h
 *
 *  Created on: Nov 1, 2024
 *      Author: yoyos
 */

#ifndef YHLIB_BUZZER_SCORES_SCORE_MARIO_H_
#define YHLIB_BUZZER_SCORES_SCORE_MARIO_H_

#include "buzzer.h"

buzzernote static const mario[127]={
		{none, 0+1, 1, 0, {0,0}},//0
		{E1,   0+1, 1, 0, {0,0}},     //!
		{E1,   0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{G1,   0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},//10
		{none, 0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{G1,   0  , 2, 0, {0,0}},     //!
		{none, 0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{C1,   0+1, 3, 0, {0,0}}, //16    //reprise
		{G1,   0,   1, 0, {0,0}},
		{none, 0,   2, 0, {0,0}},
		{E1,   0+0, 3, 0, {0,0}},
		{A1,   0+0, 2, 0, {0,0}},//20
		{B1,   0+0, 2, 0, {0,0}},
		{Ad1,  0+0, 1, 0, {0,0}},
		{A1,   0+0, 2, 0, {0,0}},
		{G1,   0+0, 2, 1, {0,0}},
		{E1,   0+1, 2, 1, {0,0}},
		{G1,   0+1, 2, 1, {0,0}},
		{A1,   0+1, 2, 0, {0,0}},
		{F1,   0+1, 1, 0, {0,0}},
		{G1,   0+1, 1, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},//30
		{E1,   0+1, 2, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 1, 0, {0,0}},
		{B1,   0,   3, 0, {16,1}},
		{none, 0,   2, 0, {0,0}},//reprise à 35
		{G1,   0+1, 1, 0, {0,0}},
		{Fd1,  0+1, 1, 0, {0,0}},
		{F1,  0+1, 1, 0, {0,0}},
		{Dd1,  0+1, 2, 0, {0,0}},
		{E1,  0+1, 1, 0, {0,0}},//40
		{none, 0,   1, 0, {0,0}},
		{G1,   0, 1, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 1, 0, {0,0}},
		{none, 0,   2, 0, {0,0}},
		{G1,   0+1, 1, 0, {0,0}},//50
		{Fd1,  0+1, 1, 0, {0,0}},
		{F1,  0+1, 1, 0, {0,0}},
		{Dd1,  0+1, 2, 0, {0,0}},
		{E1,  0+1, 1, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},
		{C1,   0+2, 2, 0, {0,0}},
		{C1,   0+2, 1, 0, {0,0}},
		{C1,   0+2, 4, 0, {0,0}},
		{none, 0,   2, 0, {0,0}},
		{G1,   0+1, 1, 0, {0,0}},//60
		{Fd1,  0+1, 1, 0, {0,0}},
		{F1,  0+1, 1, 0, {0,0}},
		{Dd1,  0+1, 2, 0, {0,0}},
		{E1,  0+1, 1, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},
		{G1,   0, 1, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},//70
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 1, 0, {0,0}},
		{none, 0,   2, 0, {0,0}},
		{Dd1,  0+1, 2, 0, {0,0}},
		{none, 0,   1, 0, {0,0}},
		{D1,  0+1, 3, 0, {0,0}},
		{C1,   0+1, 4, 0, {0,0}},
		{none, 0,   4, 0, {35,1}},
		{C1,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 2, 0, {0,0}},//80
		{C1,   0+1, 1, 0, {0,0}},
		{none,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 2, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 2, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},
		{G1,   0, 4, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 2, 0, {0,0}},//90
		{C1,   0+1, 1, 0, {0,0}},
		{none,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 1, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{none,   0+1, 8, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 2, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{none,   0+1, 1, 0, {0,0}},//100
		{C1,   0+1, 1, 0, {0,0}},
		{D1,   0+1, 2, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{C1,   0+1, 2, 0, {0,0}},
		{A1,   0, 1, 0, {0,0}},
		{G1,   0, 4, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},
		{none, 0+1, 1, 0, {0,0}},
		{E1,   0+1, 1, 0, {0,0}},//110
		{none, 0+1, 1, 0, {0,0}},
		{C1,   0+1, 1, 0, {0,0}},
		{E1,   0+1, 2, 0, {0,0}},
		{G1,   0+1, 2, 0, {0,0}},
		{none,   0+1, 2, 0, {0,0}},
		{G1,   0, 4, 0, {0,0}},
		{C1,   0+1, 3, 0, {0,0}},
		{G1,   0, 3, 0, {0,0}},
		{E1,   0, 2, 0, {0,0}},
		{A1,   0, 2, 1, {0,0}},//120
		{B1,   0, 2, 1, {0,0}},
		{A1,   0, 2, 1, {0,0}},
		{Gd1,   0, 2, 1, {0,0}},
		{Ad1,   0, 2, 1, {0,0}},
		{Gd1,   0, 2, 1, {0,0}},
		{G1,   0, 8, 0, {0,0}},
};

#endif /* YHLIB_BUZZER_SCORES_SCORE_MARIO_H_ */
