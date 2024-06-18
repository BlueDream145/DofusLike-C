/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game functions
*/

#include "my_rpg.h"
#include "str.h"

int check_fight_end(stage_t *stage)
{
	int i = 1;

	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0)
			return (1);
		i++;
	}
	return (0);
}

int change_quest(int mode, int new_value)
{
	static int value = -1;

	if (mode == 1)
		value = new_value;
	return (value);
}

static void handle_quest_book(stage_t *stage, int cur_quest)
{
	if (cur_quest == 1)
		stage->anim[1].rect.top = stage->anim[1].image_size.y;
	if (cur_quest == 2) {
		stage->anim[1].rect.top = stage->anim[1].image_size.y;
		stage->anim[2].rect.top = stage->anim[2].image_size.y;
	}
}

void handle_questes(stage_t *stage)
{
	int cur_quest;
	int cur_stage;

	cur_stage = change_stage(0, 0);
	cur_quest = change_quest(0, 0);
	if (cur_quest == 0 && cur_stage == 3)
		stage->button[PICK_UP_WATER].state = 1;
	if (cur_quest == 1 && cur_stage == 4)
		stage->button[FIX_PIPE].state = 1;
	if (cur_quest >= 2 && cur_stage == 4)
		stage->sprite[9].state = 1;
	if (check_fight_end(stage) == 1)
		change_quest(1, 3);
	if (cur_stage != 5)
		handle_quest_book(stage, cur_quest);
}
