/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** players.c
*/

#include "my_rpg.h"
#include <stdio.h>
#include "str.h"

static int init_stat(uint i, stage_t *stage, FILE *fp)
{
	size_t len = 0;
	char *buffer = get_first_line(NULL, 0);

	if (buffer == NULL)
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	stage->players[i].stamina_max = my_getnbr(buffer);
	stage->players[i].stamina = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->players[i].strength = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->players[i].level = my_getnbr(buffer);
	return (0);
}

static int init_pos(uint i, stage_t *stage, FILE *fp)
{
	size_t len = 0;
	char *buffer = NULL;

	if (getline(&buffer, &len, fp) == -1)
			return (84);
	stage->players[0].start_case.x = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->players[0].start_case.y = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	return (0);
}

int init_players(uint num, stage_t *stage, FILE *fp, gui_t *gui)
{
	if (init_stat(num, stage, fp) == 84)
		return (84);
	if (init_pos(num, stage, fp) == 84)
		return (84);
	return (0);
}
