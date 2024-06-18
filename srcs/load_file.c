/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** load_file.c
*/

#include "my_rpg.h"
#include "str.h"

int check_char(char *line)
{
	int i = 0;

	while (line[i] != '\n') {
		if (line[i] - 48 < 0 || line[i] - 48 > 9)
			return (-1);
		else
			i++;
	}
	return (0);
}

int check_file(char **file)
{
	int i = 0;
	int len = my_strlen(file[0]);

	if (len == 0)
		return (-1);
	while (file[i] != NULL) {
		if (my_strlen(file[i]) != len)
			return (-1);
		else if (check_char(file[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int **convert_map(char **map, gui_t *gui)
{
	int i = 0;
	int j = 0;
	int **copy = NULL;

	if ((copy = malloc(sizeof(int *) * gui->path.h)) == NULL)
		return (NULL);
	while (i != gui->path.h) {
		if ((copy[i] = malloc(sizeof(int) * gui->path.w)) == NULL)
			return (NULL);
		i++;
	}
	for (i = 0; i != gui->path.h; i++) {
		for (j = 0; j != gui->path.w; j++)
			copy[i][j] = map[i][j] - 48;
	}
	return (copy);
}

char **malloc_tab(FILE *stream, gui_t *gui)
{
	char **file = NULL;
	char *line = NULL;
	size_t len = 0;

	gui->path.h = 0;
	if ((file = malloc(sizeof(char *))) == NULL)
		return (NULL);
	file[0] = NULL;
	while (getline(&line, &len, stream) != -1) {
		if ((file = my_realloc(file, line)) == NULL)
			return (NULL);
		line = NULL;
		gui->path.h++;
	}
	gui->path.w = my_strlen(file[0]) - 1;
	return (file);
}

char **my_realloc(char **array, char *str)
{
	int i = 0;
	int j = 0;
	char **new = NULL;

	while (array[i] != NULL)
		i++;
	if ((new = malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	while (j != i) {
		new[j] = array[j];
		j++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	return (new);
}
