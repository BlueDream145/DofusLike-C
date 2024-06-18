/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** engine_custom.c
*/

#include "my_rpg.h"

void print_custom_player(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	stage->sprite[7].state = true;
	stage->button[PREV].state = true;
	stage->button[NEXT].state = true;
	stage->button[GENDER].state = true;
	stage->anim[1].state = true;
	stage->anim[0].state = false;
	for (int i = 0; i != PREV ; i++)
		stage->button[i].state = false;
	stage->button[EXIT_BUTTON].state = 1;
}

void custom_next(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	stage->anim[1].rect.left += 300;
	if (stage->anim[1].rect.left >= 900)
		stage->anim[1].rect.left = 0;
	sfSprite_setTextureRect(stage->anim[1].sprite, \
	stage->anim[1].rect);
	gui->custom.classe = stage->anim[1].rect.left / 300;
}

void close_custom_panel(stage_t *stage)
{
	stage->sprite[7].state = false;
	stage->sprite[9].state = false;
	stage->button[PREV].state = false;
	stage->button[NEXT].state = false;
	stage->button[GENDER].state = false;
	stage->button[BUTTON_1920].state = false;
	stage->button[BUTTON_1680].state = false;
	stage->sprite[8].state = false;
	stage->anim[1].state = 0;
	stage->anim[0].state = true;
	for (int i = 0; i != PREV; i++)
		stage->button[i].state = true;
	stage->button[EXIT_BUTTON].state = true;
	stage->sprite[8].state = false;
	stage->button[BUTTON_1680].state = false;
	stage->button[BUTTON_1920].state = false;
	stage->sprite[6].state = false;
	stage->sprite[5].state = false;
	stage->button[4].state = false;
	stage->button[6].state = false;
}
