/*
** EPITECH PROJECT, 2018
** engine_actions_handler_gui.c
** File description:
** engine_actions_handler_gui
*/

#include "my_rpg.h"

void health_potion(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	stage->players[0].stamina += 10;
	if (stage->players[0].stamina > stage->players[0].stamina_max) {
		stage->players[0].stamina
		-= stage->players[0].stamina - stage->players[0].stamina_max;
	}
}

static void activ_unactive(stage_t *stage, int start, int end, int mode)
{
	stage->sprite[5].state = mode;
	for (int i = start; i != end; i++)
		stage->button[i].state = mode;
}

void display_inventory(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	static int on_off = 0;

	if (gui->my_event[sfEvtMouseButtonPressed] != true
	&& id != -1)
		return;
	if (gui == NULL || stage == NULL)
		return;
	if (on_off == 0) {
		gui->detect_evt[HANDLE_EVT_MAP] = false;
		activ_unactive(stage, 3, 30, 1);
		on_off = 1;
	}
	else {
		gui->detect_evt[HANDLE_EVT_MAP] = true;
		activ_unactive(stage, 3, 30, 0);
		on_off = 0;
	}
}

void get_case(bag_t *my_bag, sfVector2i *case_find)
{
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			if (my_bag->my_case[i][j].moving == true) {
				case_find->x = j;
				case_find->y = i;
				return;
			}
		}
	}
	case_find->x = -1;
	case_find->y = -1;
}

void clear_case(bag_t *my_bag)
{
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			my_bag->my_case[i][j].moving = false;
		}
	}
}
