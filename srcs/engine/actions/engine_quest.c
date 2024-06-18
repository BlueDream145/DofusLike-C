/*
** EPITECH PROJECT, 2018
** engine_actions.c
** File description:
** engine_actions
*/

#include "my_rpg.h"

void replace_objet(sfVector2i *replace, int i, int j, bag_t *my_bag)
{
	if (my_bag->my_case[i][j].item == replace->x)
		my_bag->my_case[i][j].item = replace->y;
}

void start_quest(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	static int my_quest_panel[] = {10 , 11, 12, 13};
	int cur_quest = change_quest(0, 0);

	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	give_obj_quest(my_bag, cur_quest);
	stage->sprite[my_quest_panel[cur_quest]].state = 1;
}

void pick_up_water(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	sfVector2i replace;

	replace.x = 7;
	replace.y = 8;
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	change_quest(1, 1);
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++)
			replace_objet(&replace, i, j, my_bag);
	}
	stage->button[PICK_UP_WATER].state = 0;
}

void fix_pipe(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	change_quest(1, 2);
	stage->sprite[9].state = 1;
	stage->button[FIX_PIPE].state = 0;
}
