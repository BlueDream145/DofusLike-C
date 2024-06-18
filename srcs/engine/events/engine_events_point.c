/*
** EPITECH PROJECT, 2018
** engine_events_point.c
** File description:
**
*/

#include "my_rpg.h"

int button_contains_point(sfVector2f *elem_pos,
sfVector2f *elem_rect, int state, sfVector2i *pos)
{
	if (state == 1 && pos->x >= elem_pos->x
	&& pos->x <= elem_pos->x + elem_rect->x
	&& pos->y >= elem_pos->y
	&& pos->y <= elem_pos->y + elem_rect->y)
		return (1);
	return (0);
}

void disable_pause(stage_t *stage, gui_t *gui)
{
	if (change_stage(0, 0) == 0) {
		stage->sprite[6].state = 0;
		stage->button[38].state = 0;
		stage->button[39].state = 0;
		gui->pause_mode = false;
		gui->handle_event[38].on_off = true;
		gui->handle_event[39].on_off = true;
	}
}
