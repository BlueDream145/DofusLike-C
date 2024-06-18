/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** menu_action.c
*/

#include "my_rpg.h"

void print_panel_settings(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	for (int i = 0; i != PREV ; i++)
		stage->button[i].state = false;
	stage->sprite[8].state = 1;
	stage->button[BUTTON_1680].state = 1;
	stage->button[BUTTON_1920].state = 1;
	stage->sprite[6].state = 1;
	stage->sprite[5].state = 1;
	stage->button[4].state = 1;
	stage->button[6].state = 1;
}

void choose_screen_size(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	if (id == 10)
		sfRenderWindow_setSize(gui->window, (sfVector2u){1680, 1050});
	else
		sfRenderWindow_setSize(gui->window, (sfVector2u){1920, 1080});
}

void custom_prev(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	stage->anim[1].rect.left -= 300;
	if (stage->anim[1].rect.left < 0)
		stage->anim[1].rect.left = 600;
	sfSprite_setTextureRect(stage->anim[1].sprite, \
	stage->anim[1].rect);
	gui->custom.classe = stage->anim[1].rect.left / 300;
}

void handle_custom_player(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
		close_custom_panel(stage);
}

void gender(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	if (gui->custom.sex == 1) {
		stage->anim[1].rect.top = 0;
		gui->custom.sex = 0;
		stage->button[GENDER].RectButton.top = 0;

	}
	else {
		stage->anim[1].rect.top = 500;
		stage->button[GENDER].RectButton.top = 72;
		gui->custom.sex = 1;
	}
	sfSprite_setTextureRect(stage->anim[1].sprite, \
	stage->anim[1].rect);
}
