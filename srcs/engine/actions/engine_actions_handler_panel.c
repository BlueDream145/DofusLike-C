/*
** EPITECH PROJECT, 2018
** engine_actions_handler_panel.c
** File description:
** Panel
*/

#include "my_rpg.h"

void end_change_item(sfVector2i *cur_case, bag_t *my_bag)
{
	sfVector2i case_find;
	int temp;

	get_case(my_bag, &case_find);
	if (case_find.y == -1 || cur_case->y == -1 || case_find.x == -1
	|| cur_case->x == -1 || (case_find.y == cur_case->y
	&& case_find.x == cur_case->x)
	|| my_bag->my_case[case_find.y][case_find.x].item == -1) {
		clear_case(my_bag);
		return;
	}
	temp = my_bag->my_case[case_find.y][case_find.x].item;
	my_bag->my_case[case_find.y][case_find.x].item
	= my_bag->my_case[cur_case->y][cur_case->x].item;
	my_bag->my_case[cur_case->y][cur_case->x].item = temp;
	clear_case(my_bag);
}

void change_item_select(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	sfVector2i cur_case;

	cur_case.y = ((id - 3) / 4);
	cur_case.x = (id - 2) - (cur_case.y * 4) - 1;
	if (gui->my_event[sfEvtMouseButtonPressed] == true) {
		clear_case(my_bag);
		my_bag->my_case[cur_case.y][cur_case.x].moving = true;
	}
	if (gui->my_event[sfEvtMouseButtonReleased] == true)
		end_change_item(&cur_case, my_bag);
}

void unknow(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui == NULL || stage == NULL)
		return;
}

static void activ_unactive(stage_t *stage, int start, int end, int mode)
{
	stage->sprite[8].state = mode;
	for (int i = start; i != end; i++)
		stage->anim[i].state = mode;
}

void display_quests(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	static int on_off = 0;

	if (change_stage(0, 0) == 5)
		return;
	if (gui->my_event[sfEvtMouseButtonPressed] != true
	&& id != -1)
		return;
	if (on_off == 0) {
		gui->detect_evt[HANDLE_EVT_MAP] = false;
		gui->detect_evt[HANDLE_TAB] = false;
		activ_unactive(stage, 1, 4, 1);
		on_off = 1;
	}
	else {
		gui->detect_evt[HANDLE_EVT_MAP] = true;
		gui->detect_evt[HANDLE_TAB] = true;
		activ_unactive(stage, 1, 4, 0);
		on_off = 0;
	}
}
