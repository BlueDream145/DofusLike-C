/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_button
*/

#include <stdio.h>
#include "gui.h"
#include "str.h"

static void init_bag_collumn(bag_t *my_bag)
{
	static int ref_x[4] = {967, 1067, 1167, 1267};
	static int ref_y[6] = {257, 347, 437, 527, 617, 707};

	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			my_bag->ref_case[i][j].x = ref_x[j];
			my_bag->ref_case[i][j].y = ref_y[i];
		}
	}
}

static void init_ref(bag_t *my_bag)
{
	static int ref_equip_y[3] = {527, 617, 707};
	static int ref_scrl_x[4] = {939, 1005, 1070, 1136};
	static int ref_scrl_y[2] = {942, 1007};

	init_bag_collumn(my_bag);
	for (int i = 0; i != 3; i++) {
		my_bag->ref_equip[i].x = 562;
		my_bag->ref_equip[i].y = ref_equip_y[i];
	}
	for (int i = 0; i != 2; i++) {
		for (int j = 0; j != 4; j++) {
			my_bag->ref_scrl_bar[i][j].x = ref_scrl_x[j];
			my_bag->ref_scrl_bar[i][j].y = ref_scrl_y[i];
		}
	}
}

static void init_my_case(bag_t *my_bag)
{
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			my_bag->my_case[i][j].item = -1;
			my_bag->my_case[i][j].moving = 0;
		}
	}
	for (int i = 0; i != 3; i++)
		my_bag->equiped[i] = -1;
}

bag_t *init_bag(void)
{
	bag_t *my_bag = malloc(sizeof(bag_t));

	if (my_bag == NULL)
		return (NULL);
	my_bag->scroll_select = 0;
	my_bag->my_items = init_item();
	if (my_bag->my_items == NULL)
		return (NULL);
	init_my_case(my_bag);
	init_ref(my_bag);
	return (my_bag);
}
