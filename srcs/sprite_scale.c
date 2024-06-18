/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** sprite scale functions
*/

#include "my_rpg.h"

void check_scale(int dir, stage_t *stage, int i)
{
	if (stage->anim[i].dir != dir) {
		if (dir == RIGHT)
			invert_sprite(1, stage, i);
		else
			invert_sprite(-1, stage, i);
	}
	stage->anim[i].dir = dir;
}
