/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** map loading functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "str.h"

int check_map_size(void)
{
	FILE *map = fopen("config_files/map", "r");
	char buf[1];
	int i = 0;
	int h = 0;

	if (map == NULL)
		return (-1);
	for (i = 1; fread(buf, 1, 1, map) == 1; i++) {
		if (buf[0] == '\n' && i - 1 != MAP_X * 3)
			return (-1);
		else if (buf[0] == '\n') {
			h++;
			i = 0;
		}
	}
	fclose(map);
	if (h != MAP_Y)
		return (-1);
	return (0);
}

void free_map(game_t *info)
{
	int i = 0;

	while (i != MAP_Y) {
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

int **load_map(char *name, gui_t *gui)
{
	char **file = NULL;
	FILE *stream = NULL;

	if ((stream = fopen(name, "r")) == NULL) {
		my_putstr("Error loading file\n");
		return (NULL);
	}
	if ((file = malloc_tab(stream, gui)) == NULL) {
		my_putstr("Error loading file\n");
		fclose(stream);
		return (NULL);
	}
	fclose(stream);
	if (gui->path.w != 14 || gui->path.h != 40
	|| check_file(file) == -1) {
		my_putstr("Invalid map file\n");
		return (NULL);
	}
	return (convert_map(file, gui));
}
