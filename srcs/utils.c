/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** utils.c
*/

#include <stdlib.h>
#include "str.h"

char *get_first_line(char *line, int to_pass)
{
	static char *buffer = NULL;

	if (to_pass == 1) {
		if (line == NULL)
			buffer = NULL;
		else
			buffer = my_strdup(line);
	}
	return (buffer);
}

int check_comment_file(char *buffer)
{
	if (my_strcmp(buffer, "#BUTTON#\n") == 0
	|| my_strcmp(buffer, "#SPRITE#\n") == 0
	|| my_strcmp(buffer, "#PLAYERS#\n") == 0
	|| my_strcmp(buffer, "#TEXT#\n") == 0
	|| my_strcmp(buffer, "#ANIMATION#\n") == 0
	|| my_strcmp(buffer, "#ORDER#\n") == 0)
		return (0);
	return (-1);
}

int update_value(int to_pass, int reset)
{
	static int check = 0;

	if (to_pass == 1)
		check = 1;
	if (reset == 1)
		check = 0;
	return (check);
}

void check_reset_variable(int *j, int *i)
{
	if (update_value(0, 0) == 1) {
		*j = 0;
		*i = 0;
		update_value(0, 1);
	}
}
