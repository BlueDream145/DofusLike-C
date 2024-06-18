/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** Draw components
*/

#include "my_rpg.h"

static void print_item_case(int i, int j, bag_t *my_bag, gui_t *gui)
{
	int idx_itm = my_bag->my_case[i][j].item;

	if (idx_itm != -1) {
		my_bag->my_items[idx_itm].position.x = my_bag->ref_case[i][j].x;
		my_bag->my_items[idx_itm].position.y = my_bag->ref_case[i][j].y;
		sfRectangleShape_setPosition(my_bag->my_items[idx_itm].Button
		, my_bag->my_items[idx_itm].position);
		sfRenderWindow_drawRectangleShape(
		gui->window, my_bag->my_items[idx_itm].Button, NULL);
	}
}

static void print_scroll_bar(int i, int j, bag_t *my_bag, gui_t *gui)
{
	int idx_itm = my_bag->my_case[i][j].item;

	if (idx_itm != -1 && i < 2) {
		my_bag->my_items[idx_itm].position.x
		= my_bag->ref_scrl_bar[i][j].x;
		my_bag->my_items[idx_itm].position.y
		= my_bag->ref_scrl_bar[i][j].y;
		sfRectangleShape_setPosition(my_bag->my_items[idx_itm].Button
		, my_bag->my_items[idx_itm].position);
		sfRenderWindow_drawRectangleShape(
		gui->window, my_bag->my_items[idx_itm].Button, NULL);
	}
}

void handle_items(bag_t *my_bag, gui_t *gui)
{
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			print_item_case(i, j, my_bag, gui);
		}
	}
}

void handle_scroll_bar(bag_t *my_bag, gui_t *gui)
{
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			print_scroll_bar(i, j, my_bag, gui);
		}
	}
}

void move_item(bag_t *my_bag, gui_t *gui)
{
	sfVector2i case_to_print;
	int idx_itm;
	sfVector2i pos = sfMouse_getPositionRenderWindow(gui->window);

	get_case(my_bag, &case_to_print);
	if (case_to_print.x == -1 || case_to_print.y == -1)
		return;
	idx_itm = my_bag->my_case[case_to_print.y][case_to_print.x].item;
	if (case_to_print.x != -1 && case_to_print.y != -1 && idx_itm != -1) {
		my_bag->my_items[idx_itm + 9].position.x = pos.x
			- my_bag->my_items[idx_itm + 9].size.x / 2;
		my_bag->my_items[idx_itm + 9].position.y = pos.y
			- my_bag->my_items[idx_itm + 9].size.y / 2;
		sfRectangleShape_setPosition(my_bag->my_items[idx_itm + 9]
		.Button, my_bag->my_items[idx_itm + 9].position);
		sfRenderWindow_drawRectangleShape(
		gui->window, my_bag->my_items[idx_itm + 9].Button, NULL);
	}
}
