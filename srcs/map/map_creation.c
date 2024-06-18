/*
** EPITECH PROJECT, 2018
** My World
** File description:
** Map creation functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

char *get_buf(int size)
{
	FILE *map = fopen("config_files/map", "r");
	char *buf = NULL;

	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	fread(buf, size, 1, map);
	buf[size] = '\0';
	fclose(map);
	return (buf);
}

int **get_obj(char *buf, game_t info)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int **obj;

	obj = malloc(sizeof(int *) * MAP_Y);
	if (obj == NULL)
		return (NULL);
	for (i = 0; i != MAP_Y; i++) {
		obj[i] = malloc(sizeof(int) * MAP_X);
		if (obj[i] == NULL)
			return (NULL);
	}
	for (j = 0, k = 1; j != MAP_Y; j++, k++) {
		for (i = 0; i != MAP_X; i++, k += 3)
			obj[j][i] = buf[k] - 48;
	}
	return (obj);
}

int **get_map(char *buf, game_t info)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int **map;

	map = malloc(sizeof(int *) * MAP_Y);
	if (map == NULL)
		return (NULL);
	for (i = 0; i != MAP_Y; i++) {
		map[i] = malloc(sizeof(int) * MAP_X);
		if (map[i] == NULL)
			return (NULL);
	}
	for (j = 0; j != MAP_Y; j++, k++) {
		for (i = 0; i != MAP_X; i++, k += 3)
			map[j][i] = buf[k] - 48;
	}
	return (map);
}
