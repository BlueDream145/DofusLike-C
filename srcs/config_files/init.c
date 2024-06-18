/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** init.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "gui.h"
#include "str.h"

int call_function_init(FILE *fp, stage_t *stage, gui_t *gui, char *buffer)
{
	static init_func load_stage = {&init_button, &init_sprite,
	&init_animation, &init_order, &init_players, &init_text};
	static int j = 0;
	static int i = 0;

	check_reset_variable(&j, &i);
	if (check_comment_file(buffer) == 0) {
		i = 0;
		j++;
		get_first_line(NULL, 1);
		if (load_stage[j](i, stage, fp, gui) == 84)
			return (84);
	}
	else {
		get_first_line(buffer, 1);
		if (load_stage[j](i, stage, fp, gui) == 84)
			return (84);
	}
	i++;
	return (0);
}

int init_type(size_t len, FILE *fp, stage_t *stage, gui_t *gui)
{
	char *buffer = NULL;

	for (uint i = 0; getline(&buffer, &len, fp) != -1; i++) {
		if (call_function_init(fp, stage, gui, buffer) == 84)
			return (84);
		free(buffer);
		buffer = NULL;
	}
	update_value(1, 0);
	return (0);
}

int init_stage(stage_t *stage, char *path, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;
	FILE *fp = fopen(path, "r");
	char **size;
	char **temp;

	if (fp == NULL)
		return (84);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	size = my_str_to_word_array(buffer);
	if (size == NULL || init_change_stage(fp, stage, gui) == 84
	|| init_nbr_element(stage, size) == 84
	|| malloc_struct(stage, size) == 84
	|| init_type(len, fp, stage, gui) == 84) {
		return (84);
	}
	free(size);
	fclose(fp);
	return (0);
}

int handle_start_stage(int num_stage, stage_t *stage, gui_t *gui)
{
	char *file[] = {"config_files/menu.txt", "config_files/stage_1.txt"
	, "config_files/stage_2.txt", "config_files/stage_3.txt"
	, "config_files/stage_4.txt", "config_files/stage_5.txt", NULL};

	if (init_stage(stage, file[num_stage], gui) == 84)
		return (84);
	if (change_stage(0, 0) != 0) {
		init_utl_map(gui, stage);
		init_bot(gui, stage);
		init_game(stage, gui);
	}
	return (0);
}
