/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main function of the My RPG project
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "str.h"

static int check_line(char *line, char *name)
{
	int i = 0;

	while (line[i] != '=') {
		if (line[i] == '\0')
			return (1);
		if (line[i] != name[i])
			return (1);
		i++;
	}
	if (my_strcmp(&line[i + 1], ":0.0") == 0)
		return (0);
	return (1);
}

int check_env(char **env)
{
	int i = 0;

	if (env == NULL)
		return (1);
	while (env[i] != NULL) {
		if (check_line(env[i], "DISPLAY") == 0)
			return (0);
		i++;
	}
	return (1);
}
