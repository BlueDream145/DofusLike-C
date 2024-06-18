/*
** EPITECH PROJECT, 2018
** engine_actions.c
** File description:
** engine_actions
*/

#include <stdlib.h>
#include "my_rpg.h"

void prepare_actions_dictionary(gui_t *gui)
{
	gui->handle_event = init_evt_menu();
}

void dispatch_action(stage_t *stage, int id, gui_t *gui, bag_t *my_bag)
{
	if (gui->handle_event[id].actions_handlers != NULL
	&& gui->handle_event[id].on_off == 0)
		gui->handle_event[id].actions_handlers(gui, stage, my_bag, id);
}

void save(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] != true
	&& id != -1)
		return;
	gui->running = false;
	save_game(gui, stage, my_bag);
}

void exit_button(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	if (gui == NULL || stage == NULL)
		return;
	gui->running = false;
}

void go_menu(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	change_stage(1, 0);
}
