/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
** Run graphics
*/

#include "my_rpg.h"

int handle_clok_start_anim(int *start, sfClock *my_clock, stage_t *stage)
{
	static sfTime real_time;
	static float time_sec;

	real_time = sfClock_getElapsedTime(my_clock);
	time_sec = sfTime_asSeconds(real_time);
	stage->sprite[10].state = 1;
	stage->anim[2].state = 1;
	if (time_sec > 3 || sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue) {
		*start = true;
		stage->sprite[10].state = 0;
		stage->anim[2].state = 0;
	}
	return (0);
}
