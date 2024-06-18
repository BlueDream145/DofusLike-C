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

sfVector2f iso_pnt(int x, int y)
{
	sfVector2f point2d = {0};

	point2d.x = COS * x - COS * y;
	point2d.y = SIN * y + SIN * x;
	return (point2d);
}

static int check_click_is_inside(int x, int y, t_pos pos)
{
	if (x < pos.lef.x || x > pos.rig.x || y > pos.top.y || y < pos.bot.y)
		return (1);
	if (x <= pos.bot.x && y <= pos.lef.y)
		if ((y - pos.bot.y) * (pos.bot.x - pos.lef.x)
		< (pos.lef.y - pos.bot.y) * (pos.bot.x - x))
			return (1);
	if (x >= pos.bot.x && y <= pos.rig.y)
		if ((y - pos.bot.y) * (pos.rig.x - pos.bot.x)
		< (pos.rig.y - pos.bot.y) * (x - pos.bot.x))
			return (1);
	if (x >= pos.top.x && y >= pos.rig.y)
		if ((pos.top.y - y) * (pos.rig.x - pos.top.x)
		< (pos.top.y - pos.rig.y) * (x - pos.top.x))
			return (1);
	if (x <= pos.top.x && y >= pos.lef.y)
		if ((pos.top.y - y) * (pos.top.x - pos.lef.x)
		< (pos.top.y - pos.lef.y) * (pos.top.x - x))
			return (1);
	return (0);
}

int check_tile(int i, int j, gui_t *gui)
{
	sfVector2f *tile = NULL;
	t_pos p;

	tile = get_tile(i, j, gui);
	p.lef = tile[2];
	p.rig = tile[1];
	p.top = tile[0];
	p.bot = tile[3];
	if (check_click_is_inside(gui->game.mx, gui->game.my, p) == 0)
		return (1);
	return (0);
}

int check_mouse_click(gui_t *gui, stage_t *stage)
{
	int i = 0;
	int j = 0;

	gui->game.mx = gui->event.mouseButton.x;
	gui->game.my = gui->event.mouseButton.y;
	for (i = 0; i != MAP_Y; i++) {
		for (j = 0; j != MAP_X; j++) {
			if (check_tile(j, i, gui) == 1 \
			&& gui->game.map[i][j] == 0) {
				gui->path.xB = j;
				gui->path.yB = i;
				pathfinding(gui, &stage->players[0]);
				return (1);
			}
		}
	}
	return (0);
}

void handle_event_map(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == true) {
		if (gui->event.mouseButton.button == 0)
			check_mouse_click(gui, stage);
		else if (gui->event.mouseButton.button == 1)
			check_player_attack(gui, stage);
	}
}
