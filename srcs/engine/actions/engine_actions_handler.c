/*
** EPITECH PROJECT, 2018
** engine_actions_handler.c
** File description:
** engine_actions_handler
*/

#include "my_rpg.h"

void load_game_action(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	if (gui == NULL || stage == NULL)
		return;
	change_stage(1, 1);
}

void new_game_action(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui == NULL || stage == NULL)
		return;
}

void settings(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui == NULL || stage == NULL)
		return;
}

void setings_sound(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui == NULL || stage == NULL)
		return;
}