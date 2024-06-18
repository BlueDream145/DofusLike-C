/*
** EPITECH PROJECT, 2018
** engine_events_handler.c
** File description:
** Handlers for events
*/

#include "my_rpg.h"
#include "str.h"

static void set_new_value(stage_t *stage, gui_t *gui, int i)
{
	sfRectangleShape_setTextureRect(stage->button[i].Button
	, stage->button[i].RectButton);
	sfRectangleShape_setTextureRect(gui->cursor.Button
	, gui->cursor.RectButton);
}

static void change_pos_mouse(gui_t *gui, int len, int *succes, int i)
{
	if (len - 1 == i) {
		if (*succes == 0)
			gui->cursor.RectButton.left = 0;
		else
			*succes = 0;
	}
}

static void handle_pos_cursor(gui_t *gui, sfVector2i *pos)
{
	gui->cursor.position.x = pos->x;
	gui->cursor.position.y = pos->y;
	if (gui->cursor.RectButton.left != 0)
		gui->cursor.position.x = pos->x - 7;
	sfRectangleShape_setPosition(gui->cursor.Button, gui->cursor.position);
}

static void appli_over_button_on(stage_t *stage, gui_t *gui, int i, int *succes)
{
	*succes = 1;
	if (gui->my_event[sfEvtMouseButtonPressed] == true) {
		stage->button[i].RectButton.left
		= stage->button[i].size.x * 2 ;
		gui->cursor.RectButton.left = gui->cursor.size.x * 2;
	}
	else {
		stage->button[i].RectButton.left
		= stage->button[i].size.x;
		gui->cursor.RectButton.left = gui->cursor.size.x;
	}
}

void over_button(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(gui->window);
	int len = my_getnbr(stage->nbr_elem[0]);
	static int succes = 0;

	if (gui == NULL || stage == NULL)
		return;
	for (int i = 0; i < len; i++) {
		if (button_contains_point(&stage->button[i].position
		, &stage->button[i].size, stage->button[i].state, &pos) == 1)
			appli_over_button_on(stage, gui, i, &succes);
		else {
			if (my_bag->scroll_select != i - 30)
				stage->button[i].RectButton.left = 0;
		}
		set_new_value(stage, gui, i);
		change_pos_mouse(gui, len, &succes, i);
	}
	handle_pos_cursor(gui, &pos);
}
