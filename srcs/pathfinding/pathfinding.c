/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** pathfinding functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_rpg.h"

static int **cpy_map(int **map, path_t *info)
{
	int i = 0;
	int j = 0;
	int **copy = NULL;

	if ((copy = malloc(sizeof(int *) * info->h)) == NULL)
		return (NULL);
	while (i != info->h) {
		if ((copy[i] = malloc(sizeof(int) * info->w)) == NULL)
			return (NULL);
		i++;
	}
	for (i = 0; i != info->h; i++) {
		for (j = 0; j != info->w; j++)
			if (map[i][j] != 0)
				copy[i][j] = -1;
			else
				copy[i][j] = map[i][j];
	}
	return (copy);
}

void reset_map(int **map)
{
	int i = 0;
	int j = 0;

	while (i != 40) {
		while (j != 14) {
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int pathfinding(gui_t *gui, players_t *player)
{
	int **map = NULL;

	gui->path.dist = -1;
	gui->path.num = 1;
	gui->path.val = 0;
	if ((map = cpy_map(gui->game.map, &gui->path)) == NULL)
		return (-1);
	if (finder(map, player->x, player->y, &gui->path) == 1) {
		gui->path.num = 1;
		reset_map(player->path);
		draw_path(gui->path.xB, gui->path.yB
		, map, player->path, &gui->path);
	}
	return (0);
}
