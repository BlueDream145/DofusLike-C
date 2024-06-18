/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_sprite
*/

#include "gui.h"
#include "str.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void invert_sprite(int scale, stage_t *stage, int i)
{
	sfSprite_setScale(stage->anim[i].sprite, (sfVector2f){scale, 1});
}

static int init_sprite_origin(FILE * fp, uint num, stage_t *stage)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->sprite[num].OriginSprite.x = my_getnbr(buffer);
	free(buffer);
	buffer = NULL;
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->sprite[num].OriginSprite.y = my_getnbr(buffer);
	sfSprite_setOrigin(stage->sprite[num].sprite
	, stage->sprite[num].OriginSprite);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->sprite[num].state = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	free(buffer);
	return (0);
}

static int init_pos_sprite(FILE * fp, uint num, stage_t *stage)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->sprite[num].positionSprite.x = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == 84)
		return (84);
	stage->sprite[num].positionSprite.y = my_getnbr(buffer);
	sfSprite_setPosition(stage->sprite[num].sprite,
	stage->sprite[num].positionSprite);
	free(buffer);
	return (0);
}

static int init_texture_sprite(uint num, FILE *fp
, stage_t *stage)
{
	int len_1 = 0;
	size_t len = 0;
	char *buffer = get_first_line(NULL, 0);

	stage->sprite[num].sprite = sfSprite_create();
	if (stage->sprite[num].sprite == NULL)
		return (84);
	if (buffer == NULL)
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	len_1 = my_strlen(buffer);
	buffer[len_1 - 1] = '\0';
	stage->sprite[num].textureSprite
	= sfTexture_createFromFile(buffer, NULL);
	if (stage->sprite[num].textureSprite == NULL)
		return (84);
	sfSprite_setTexture(stage->sprite[num].sprite
	, stage->sprite[num].textureSprite, sfTrue);
	free(buffer);
	return (0);
}

int init_sprite(uint num, stage_t *stage, FILE *fp, gui_t *gui)
{
	if (init_texture_sprite(num, fp, stage) == 84
	|| init_pos_sprite(fp, num, stage) == 84
	|| init_sprite_origin(fp, num, stage) == 84)
		return (84);
	return (0);
}
