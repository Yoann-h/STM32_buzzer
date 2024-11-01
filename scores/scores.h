/*
 * scores.h
 *
 *  Created on: Nov 1, 2024
 *      Author: yoyos
 */

#ifndef YHLIB_BUZZER_SCORES_SCORES_H_
#define YHLIB_BUZZER_SCORES_SCORES_H_

#include "buzzer_cfg.h"

#ifdef BUZZER_MARIO
#include "score_mario.h"
#endif
#ifdef BUZZER_ZELDA
#include "score_zelda.h"
#endif
#ifdef BUZZER_POKEMON
#include "score_pokemon.h"
#endif

typedef enum {
#ifdef BUZZER_MARIO
	mario_theme,
#endif
#ifdef BUZZER_ZELDA
	zelda_theme,
#endif
#ifdef BUZZER_POKEMON
    pokemon_battletheme,
#endif
	theme_nb
} buzzer_songs;

buzzernote* scorelist[theme_nb]=
{
#ifdef BUZZER_MARIO
	mario,
#endif
#ifdef BUZZER_ZELDA
	zelda,
#endif
#ifdef BUZZER_POKEMON
    pokemon,
#endif
};

#endif /* YHLIB_BUZZER_SCORES_SCORES_H_ */
