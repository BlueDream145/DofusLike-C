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

static int init_player(stage_t *stage, gui_t *gui)
{
	sfVector2f *tile = get_tile(stage->players[0].start_case.x
	, stage->players[0].start_case.y, gui);

	if (tile == NULL)
		return (-1);
	affect_new_pos_player_map(stage, gui);
	if (story_chgmt_map(0, 0) == -1) {
		stage->anim[0].position.x = (int)tile[2].x;
		stage->anim[0].position.y = (int)tile[3].y;
		stage->players[0].new.x = stage->anim[0].position.x;
		stage->players[0].new.y = stage->anim[0].position.y;
		stage->players[0].x = stage->players[0].start_case.x;
		stage->players[0].y = stage->players[0].start_case.y;
	}
	stage->anim[0].way = FACE;
	stage->anim[0].dir = RIGHT;
	gui->fight_mode = 0;

	return (0);
}

int **malloc_path(void)
{
	int i = 0;
	int **path = NULL;

	if ((path = malloc(sizeof(int *) * 40)) == NULL)
		return (NULL);
	while (i != 40) {
		if ((path[i] = malloc(sizeof(int) * 14)) == NULL)
			return (NULL);
		i++;
	}
	return (path);
}

int init_game(stage_t *stage, gui_t *gui)
{
	sfVector2f *tile = get_tile(0, 0, gui);

	if (tile == NULL)
		return (-1);
	gui->game.shiftx = tile[1].x - tile[2].x;
	gui->game.shifty = tile[0].y - tile[3].y;
	if (init_player(stage, gui) != 0)
		return (-1);
	if (!(gui->game.map = load_map(gui->path_map, gui)))
		return (-1);
	if (!(stage->players[0].path = malloc_path()))
		return (-1);
	reset_map(stage->players[0].path);
	stage->players[0].clock = sfClock_create();
	return (0);
}
