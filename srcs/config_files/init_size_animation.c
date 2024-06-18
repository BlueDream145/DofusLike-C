/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** init_size_animation.c
*/

#include "my_rpg.h"
#include "str.h"

int init_rect_animation(uint num, stage_t *stage, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	stage->anim[num].rect.left = 0;
	stage->anim[num].rect.top = 0;
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].rect.width = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].advance = my_getnbr(buffer);
	buffer = free_getline(buffer);
	return (0);
}

int init_pos_animation(uint num, stage_t *stage, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].position.x = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].position.y = my_getnbr(buffer);
	buffer = free_getline(buffer);
}

int init_size_animation(uint num, stage_t *stage, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (init_pos_animation(num, stage, fp) == 84
	|| getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].image_size.x = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].image_size.y = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[num].rect.height = my_getnbr(buffer);
	if (init_rect_animation(num, stage, fp) == 84)
		return (84);
	free(buffer);
	return (0);
}

void apply_rect_animation(stage_t *stage , int i)
{
	sfSprite_setTexture(stage->anim[i].sprite
	, stage->anim[i].anim_texture, 0);
	sfSprite_setPosition(stage->anim[i].sprite
	, stage->anim[i].position);
	sfSprite_setOrigin(stage->anim[i].sprite
	, stage->anim[i].anim_origin);
	sfSprite_setTextureRect(stage->anim[i].sprite
	, stage->anim[i].rect);
}

int init_anim_origin(stage_t *stage, int i, FILE *fp)
{
	size_t len = 0;
	char *buffer = NULL;

	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[i].anim_origin.x = my_getnbr(buffer);
	buffer = free_getline(buffer);
	if (getline(&buffer , &len , fp) == -1)
		return (84);
	stage->anim[i].anim_origin.y = my_getnbr(buffer);
	free(buffer);
}
