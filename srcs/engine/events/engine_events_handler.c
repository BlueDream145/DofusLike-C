/*
** EPITECH PROJECT, 2018
** engine_events_handler.c
** File description:
** Handlers for events
*/

#include "my_rpg.h"
#include "str.h"

void handle_game_pause(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	disable_pause(stage, gui);
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue);
		if (gui->pause_mode == false) {
			gui->pause_mode = true;
			stage->sprite[6].state = 1;
			stage->button[38].state = 1;
			stage->button[39].state = 1;
			gui->handle_event[38].on_off = false;
			gui->handle_event[39].on_off = false;
		}
		else {
			stage->sprite[6].state = 0;
			stage->button[38].state = 0;
			stage->button[39].state = 0;
			gui->pause_mode = false;
			gui->handle_event[38].on_off = true;
			gui->handle_event[39].on_off = true;
		}
	}
}

void find_click_button(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(gui->window);
	int len = my_getnbr(stage->nbr_elem[0]);

	if (gui == NULL || stage == NULL)
		return;
	for (int i = 0; i < len; i++) {
		if (button_contains_point(&stage->button[i].position
		, &stage->button[i].size, stage->button[i].state, &pos) == 1) {
			dispatch_action(stage, i, gui, my_bag);
			break;
		}
	}
}

void reset(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	if (gui->my_event[sfEvtMouseButtonReleased] == true)
		clear_case(my_bag);
	if (change_stage(0, 0) == 1
	&& sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		for (int i = 10; i != 14; i++)
			stage->sprite[i].state = 0;
	}
}

void handle_tab(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	int static still = 0;

	if (still == 0 && sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
		still = 1;
		display_inventory(gui, stage, my_bag, -1);
	}
	else
		still = 0;
}

void handle_keys_bar(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	int static still[8] = {0};
	static int ref[] = {sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4};

	for (int i = 0; i != 4; i++) {
		if (still[i + 4] == 0
		&& sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue
		&& sfKeyboard_isKeyPressed(ref[i]) == sfTrue) {
			still[i + 4] = 1;
			my_bag->scroll_select = i + 4;
		}
		else if (still[i] == 0
		&& sfKeyboard_isKeyPressed(ref[i]) == sfTrue
		&& sfKeyboard_isKeyPressed(sfKeyLShift) != sfTrue) {
			still[i] = 1;
			my_bag->scroll_select = i;
		}
		else {
			still[i + 4] = 0;
			still[i] = 0;
		}
	}
}
