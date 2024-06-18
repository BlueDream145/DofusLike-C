/*
** EPITECH PROJECT, 2018
** draw.c
** File description:
** Draw components
*/

#include "my_rpg.h"

void draw_graphics(gui_t *gui, stage_t *stage, bag_t *my_bag)
{
	print_stage(gui, stage);
	if (change_stage(0, 0) != 0) {
		if (stage->sprite[5].state == 1) {
			handle_items(my_bag, gui);
			move_item(my_bag, gui);
		}
		handle_scroll_bar(my_bag, gui);
	}
	sfRenderWindow_drawRectangleShape(gui->window
	, gui->cursor.Button, NULL);
}
