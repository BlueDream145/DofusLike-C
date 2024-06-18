/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** check attacks from player and bot functions
*/

#include "my_rpg.h"
#include "str.h"

static void attack_player(stage_t *stage, int i, gui_t *gui)
{
	sfTime time = sfClock_getElapsedTime(stage->players[i].c_attack);
	int x = (int)stage->anim[0].position.x + 50;
	int y = (int)stage->anim[0].position.y + 30;
	sfVector2i pos = {x, y};

	update_particles(gui, sfRed, pos);
	if (time.microseconds >= 1000000) {
		if (stage->players[0].state == 0
		&& stage->players[0].stamina > 0) {
			stage->players[0].stamina -= stage->players[i].strength;
			sfClock_restart(stage->players[i].c_attack);
		}
		if (stage->players[0].stamina <= 0)
			change_stage(1, 0);
	}
}

void check_bot_attack(stage_t *stage, gui_t *gui)
{
	int i = 1;

	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0 && stage->players[i].state == 0) {
			attack_player(stage, i, gui);
		}
		i++;
	}
}

static void attack_bot(stage_t *stage, int i)
{
	stage->players[i].stamina -= stage->players[0].strength;
	if (stage->players[i].stamina == 0)
		stage->anim[i].state = 0;
}

static void check_if_bot(stage_t *stage, int x, int y)
{
	int i = 1;

	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0 && \
		stage->players[i].state == 0 && \
		stage->players[i].x == x && stage->players[i].y == y) {
			attack_bot(stage, i);
		}
		i++;
	}
}

void check_player_attack(gui_t *gui, stage_t *stage)
{
	int i = 0;
	int j = 0;

	if (stage->players[0].state != 0)
		return;
	gui->game.mx = gui->event.mouseButton.x;
	gui->game.my = gui->event.mouseButton.y;
	for (i = 0; i != MAP_Y; i++) {
		for (j = 0; j != MAP_X; j++) {
			if (check_tile(j, i, gui) == 1 \
			&& gui->game.map[i][j] == 0) {
				check_if_bot(stage, j, i);
			}
		}
	}
}
