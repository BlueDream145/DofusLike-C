/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** animation.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "gui.h"
#include "str.h"

int init_clock(stage_t *stage, int i, FILE *fp)
{
	size_t len = 0;
	char *buffer = NULL;

	stage->anim[i].clock = sfClock_create();
	if (stage->anim[i].clock == NULL)
		return (84);
	stage->anim[i].time = sfClock_getElapsedTime(stage->anim[i].clock);
	stage->anim[i].time_sec = sfTime_asSeconds(stage->anim[i].time);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[i].delay = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1
	|| init_anim_origin(stage, i, fp) == 84)
		return (84);
	stage->anim[i].state = my_getnbr(buffer);
	buffer = free_getline(buffer);
	free(buffer);
	return (0);
}

int apply_path(char *path, uint num, stage_t *stage)
{
	int len_1 = 0;

	len_1 = my_strlen(path);
	path[len_1 - 1] = '\0';
	stage->anim[num].sprite = sfSprite_create();
	if (stage->anim[num].sprite == NULL)
		return (84);
	stage->anim[num].anim_texture
	= sfTexture_createFromFile(path, NULL);
	if (stage->anim[num].sprite == NULL)
		return (84);
	sfSprite_setTexture(stage->anim[num].sprite
	, stage->anim[num].anim_texture, sfTrue);
	return (0);
}

char *check_path(FILE *fp, gui_t *gui)
{
	char *path = NULL;
	size_t len = 0;
	char *buffer = NULL;

	path = my_strdupcat(NULL
	, my_strdup(class_path[gui->custom.classe]));
	if (gui->custom.sex == 1)
		path = my_strdupcat(path, my_strdup(case_female));
	else
		path = my_strdupcat(path, my_strdup(case_male));
	if (getline(&buffer, &len, fp) == -1)
		return (NULL);
	path = my_strdupcat(path, buffer);
	return (path);
}

int init_animation_sprite(uint num, FILE *fp
, stage_t *stage, gui_t *gui)
{
	char *buffer = get_first_line(NULL, 0);
	char *path = NULL;
	size_t len = 0;

	if (buffer == NULL)
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	if (my_strcmp(buffer, "CHARACTER\n") == 0)
		path = check_path(fp, gui);
	else
		if (getline(&path, &len, fp) == -1)
			return (84);
	return (apply_path(path, num, stage));
}

int init_animation(uint num, stage_t *stage, FILE *fp, gui_t *gui)
{
	size_t len = 0;
	char *buffer = NULL;

	if (init_animation_sprite(num, fp, stage, gui) == 84
	|| init_size_animation(num, stage, fp) == 84
	|| init_clock(stage, num, fp) == 84)
		return (84);
	apply_rect_animation(stage, num);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	free(buffer);
	return (0);
}
