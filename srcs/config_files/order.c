/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_order
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "str.h"
#include "gui.h"

int init_order(uint num, stage_t *stage, FILE *fp, gui_t *gui)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->order[num].type = my_getnbr(buffer);
	free(buffer);
	buffer = NULL;
	if (getline(&buffer, &len, fp) == 84)
		return (84);
	stage->order[num].num = my_getnbr(buffer);
	free(buffer);
	return (0);
}
