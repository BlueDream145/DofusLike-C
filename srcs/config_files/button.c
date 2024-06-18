/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_button
*/

#include <stdio.h>
#include "gui.h"
#include "str.h"

static int head_button(FILE * fp, stage_t *stage
, uint num)
{
	size_t len = 0;
	int len_1 = 0;
	char *buffer = get_first_line(NULL, 0);

	if (buffer == NULL) {
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	}
	len_1 = my_strlen(buffer);
	buffer[len_1 - 1] = '\0';
	stage->button[num].Button = sfRectangleShape_create();
	if (stage->button[num].Button == NULL)
		return (84);
	stage->button[num].texture = sfTexture_createFromFile(buffer, NULL);
	if (stage->button[num].texture == NULL) {
		return (84);
	}
	free(buffer);
	return (0);
}

static int apply_function_for_rect(stage_t *stage, int i)
{
	sfRectangleShape_setTexture(stage->button[i].Button
	, stage->button[i].texture, 0);
	sfRectangleShape_setSize(stage->button[i].Button
	, stage->button[i].size);
	sfRectangleShape_setPosition(stage->button[i].Button
	, stage->button[i].position);
	sfRectangleShape_setTextureRect(stage->button[i].Button
	, stage->button[i].RectButton);
	return (0);
}

static int init_size_origin_button(uint num, stage_t *stage, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->button[num].RectButton.left = 0;
	stage->button[num].RectButton.top = 0;
	stage->button[num].size.x = my_getnbr(buffer);
	stage->button[num].RectButton.width = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->button[num].size.y = my_getnbr(buffer);
	stage->button[num].RectButton.height = my_getnbr(buffer);
	free(buffer);
	return (0);
}

static int init_pos_button(uint num, stage_t *stage, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == 84)
		return (84);
	stage->button[num].position.x = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == 84)
		return (84);
	stage->button[num].position.y = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->button[num].state = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	free(buffer);
	return (0);
}

int init_button(uint num, stage_t *stage, FILE * fp, gui_t *gui)
{
	if (head_button(fp, stage, num) == 84
	|| init_size_origin_button(num, stage, fp) == 84
	|| init_pos_button(num, stage, fp) == 84)
		return (84);
	apply_function_for_rect(stage, num);
	return (0);
}
