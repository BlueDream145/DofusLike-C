/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** init_size_memory.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "str.h"

static int init_where_spawn(FILE *fp, stage_t *stage, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;
	char **scene;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	scene = my_str_to_word_array(buffer);
	if (scene == NULL)
		return (84);
	stage->spawn[0].x = my_getnbr(scene[1]);
	stage->spawn[0].y = my_getnbr(scene[2]);
	stage->spawn[1].x = my_getnbr(scene[3]);
	stage->spawn[1].y = my_getnbr(scene[4]);
	stage->spawn[2].x = my_getnbr(scene[5]);
	stage->spawn[2].y = my_getnbr(scene[6]);
	free(scene);
	return (0);
}

static int init_path_map(FILE *fp, stage_t *stage, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;
	char **scene;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '\n')
			buffer[i] = '\0';
	}
	gui->path_map = my_strdup(buffer);
	free(buffer);
	return (0);
}

static int init_where_change_map(FILE *fp, stage_t *stage, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;
	char **scene;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	scene = my_str_to_word_array(buffer);
	if (scene == NULL)
		return (84);
	stage->ref[0].x = my_getnbr(scene[1]);
	stage->ref[0].y = my_getnbr(scene[2]);
	stage->ref[1].x = my_getnbr(scene[3]);
	stage->ref[1].y = my_getnbr(scene[4]);
	stage->ref[2].x = my_getnbr(scene[5]);
	stage->ref[2].y = my_getnbr(scene[6]);
	free(scene);
	return (0);
}

static int init_which_scene(FILE *fp, stage_t *stage, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;
	char **scene;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	scene = my_str_to_word_array(buffer);
	if (scene == NULL)
		return (84);
	stage->next_scene[0] = my_getnbr(scene[1]);
	stage->next_scene[1] = my_getnbr(scene[2]);
	stage->next_scene[2] = my_getnbr(scene[3]);
	free(scene);
	return (0);
}

int init_change_stage(FILE *fp, stage_t *stage, gui_t *gui)
{
	if (init_which_scene(fp, stage, gui) == 84
	|| init_where_change_map(fp, stage, gui) == 84
	|| init_path_map(fp, stage, gui) == 84
	|| init_where_spawn(fp, stage, gui) == 84)
		return (84);
	return (0);
}
