/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** move bot functions
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "str.h"

int init_bot(gui_t *gui, stage_t *stage)
{
	int i = 1;
	sfVector2f *tile = get_tile(6, 20, gui);

	if (tile == NULL)
		return (-1);
	while (i != my_getnbr(stage->nbr_elem[4])) {
		stage->players[i].new.x = stage->anim[i].position.x;
		stage->players[i].new.y = stage->anim[i].position.y;
		stage->players[i].x = 6;
		stage->players[i].y = 20;
		stage->players[i].state = 0;
		stage->anim[i].dir = RIGHT;
		stage->players[i].path = malloc_path();
		reset_map(stage->players[i].path);
		stage->players[i].clock = sfClock_create();
		stage->players[i].c_attack = sfClock_create();
		stage->players[i].agro = 0;
		stage->players[i].stamina = 100;
		i++;
	}
	return (0);
}

void get_bot_pos(gui_t *gui, stage_t *stage, int *posx, int *posy)
{
	int x = 0;
	int y = 0;

	while (gui->game.map[stage->players[0].y + y]
	[stage->players[0].x + x] != 0 || (x == 0 && y == 0)) {
		x = rand() % (1 - (-1) + 1) + (-1);
		y = rand() % (1 - (-1) + 1) + (-1);
		if (stage->players[0].x + x < 0)
			x = 0;
		if (stage->players[0].x + x > 13)
			x = 13;
		if (stage->players[0].y + y < 0)
			y = 0;
		if (stage->players[0].y + y > 39)
			x = 39;
	}
	posx[0] = x;
	posy[0] = y;
}

void gen_rand_pos(gui_t *gui, stage_t *stage, players_t *bot)
{
	int x = rand() % 14;
	int y = rand() % 40;
	int posx = 0;
	int posy = 0;

	if (bot->agro == 1 && stage->players[0].state == 1) {
		get_bot_pos(gui, stage, &posx, &posy);
		gui->path.xB = stage->players[0].x + posx;
		gui->path.yB = stage->players[0].y + posy;
		pathfinding(gui, bot);
	}
	else if (bot->agro == 0) {
		if (gui->game.map[y][x] == 0) {
			gui->path.xB = x;
			gui->path.yB = y;
			pathfinding(gui, bot);
		}
	}
}

void check_agro(gui_t *gui, stage_t *stage, players_t *bot)
{
	int x = stage->players[0].x - bot->x;
	int y = stage->players[0].y - bot->y;

	if (x < 0)
		x = x * (-1);
	if (y < 0)
		y = y * (-1);
	if (x + y <= 7) {
		bot->agro = 1;
		get_bot_pos(gui, stage, &x, &y);
		gui->path.xB = stage->players[0].x + x;
		gui->path.yB = stage->players[0].y + y;
		pathfinding(gui, bot);
	}
}

void gen_bot_pos(gui_t *gui, stage_t *stage)
{
	int i = 1;

	if (change_stage(0, 0) != 5)
		return;
	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0 && stage->players[i].agro == 0)
			check_agro(gui, stage, &stage->players[i]);
		if (stage->anim[i].state != 0 && stage->players[i].state == 0)
			gen_rand_pos(gui, stage, &stage->players[i]);
		i++;
	}
}
