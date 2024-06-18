/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my_rpg.h"

static void move_player_x(stage_t *stage, int i)
{
	float pix = 4;

	if (stage->anim[i].position.x < stage->players[i].new.x) {
		check_scale(RIGHT, stage , i);
		stage->anim[i].rect.top = 520;
		if (stage->anim[i].position.x + pix > stage->players[i].new.x)
			stage->anim[i].position.x = stage->players[i].new.x;
		else
			stage->anim[i].position.x += pix;
	}
	else {
		check_scale(LEFT, stage , i);
		stage->anim[i].rect.top = 520;
		if (stage->anim[i].position.x - pix < stage->players[i].new.x)
			stage->anim[i].position.x = stage->players[i].new.x;
		else
			stage->anim[i].position.x -= pix;
	}
}

static int move_player_y(stage_t *stage, int i)
{
	float pix = 2.2;

	if (stage->anim[i].position.y < stage->players[i].new.y) {
		if (stage->anim[i].position.y + pix > stage->players[i].new.y)
			stage->anim[i].position.y = stage->players[i].new.y;
		else
			stage->anim[i].position.y += pix;
		return (1);
	}
	else {
		if (stage->anim[i].position.y - pix < stage->players[i].new.y)
			stage->anim[i].position.y = stage->players[i].new.y;
		else
			stage->anim[i].position.y -= pix;
		return (2);
	}
}

static void move_player_diag(stage_t *stage, int i)
{
	move_player_x(stage, i);
	if (move_player_y(stage, i) == 1) {
		stage->anim[i].rect.top = 260;
		stage->anim[i].way = DIAG_F;
	}
	else {
		stage->anim[i].rect.top = 780;
		stage->anim[i].way = DIAG_B;
	}
}

static void move_player_axis(stage_t *stage, int i)
{
	if (stage->anim[i].position.x != stage->players[i].new.x) {
		move_player_x(stage, i);
		stage->anim[i].way = SIDE;
	}
	else {
		if (move_player_y(stage, i) == 1) {
			stage->anim[i].rect.top = 0;
			stage->anim[i].way = FACE;
		}
		else {
			stage->anim[i].rect.top = 1040;
			stage->anim[i].way = BACK;
		}
	}
}

void move_player(stage_t *stage, int i)
{
	sfTime Time;

	Time = sfClock_getElapsedTime(stage->players[i].clock);
	if (Time.microseconds >= 8000) {
		if (stage->anim[i].position.x != stage->players[i].new.x
		&& stage->anim[i].position.y != stage->players[i].new.y)
			move_player_diag(stage, i);
		else
			move_player_axis(stage , i);
		sfClock_restart(stage->players[i].clock);
	}
}
