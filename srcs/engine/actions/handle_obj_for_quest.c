/*
** EPITECH PROJECT, 2018
** engine_actions.c
** File description:
** engine_actions
*/

#include "my_rpg.h"

static void quest_one(bag_t *my_bag)
{
	change_quest(1, 0);
	my_bag->my_case[0][0].item = 7;
}

static void quest_two(bag_t *my_bag)
{
	sfVector2i replace;

	replace.x = 8;
	replace.y = -1;
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++)
			replace_objet(&replace, i, j, my_bag);
	}
}

static void quest_three(bag_t *my_bag)
{
	my_bag->my_case[0][0].item = 0;
	my_bag->my_case[0][1].item = 4;
}

static void quest_four(bag_t *my_bag)
{
	my_bag->my_case[5][0].item = 3;
	my_bag->my_case[5][1].item = 1;
}

void give_obj_quest(bag_t *my_bag, int cur_quest)
{
	if (cur_quest == -1)
		quest_one(my_bag);
	if (cur_quest == 1)
		quest_two(my_bag);
	if (cur_quest == 2)
		quest_three(my_bag);
	if (cur_quest == 3)
		quest_four(my_bag);
}
