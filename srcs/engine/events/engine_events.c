/*
** EPITECH PROJECT, 2018
** engine_events.c
** File description:
** Manage events
*/

#include "my_rpg.h"

static void handle_select_bar(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	static int cur_slc = -1;

	if (cur_slc != my_bag->scroll_select) {
		stage->button[my_bag->scroll_select + 30].RectButton.left
		= stage->button[my_bag->scroll_select + 30].size.x;
		sfRectangleShape_setTextureRect(stage
		->button[my_bag->scroll_select + 30].Button
		, stage->button[my_bag->scroll_select + 30].RectButton);
		cur_slc = my_bag->scroll_select;
	}
}

static void call_event_in_map(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	static go_find_evt find_evts[] =
	{handle_event_map, find_click_button, reset
	, over_button, handle_tab, handle_keys_bar, handle_game_pause};

	handle_select_bar(stage, gui, my_bag);
	for (int i = 0; i != HANDLE_CUSTOM_PLAYER; i++) {
		if (gui->detect_evt[i] == true) {
			find_evts[i](stage, gui, my_bag);
		}
	}
}

static void call_event_in_menu(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	static go_find_evt find_evts_in_map[] =
	{find_click_button, reset, over_button, handle_custom_player};

	for (int i = 0; i != 4; i++) {
		if (gui->detect_evt[i] == true)
			find_evts_in_map[i](stage, gui, my_bag);
	}
}

void dispatch_event(stage_t *stage, gui_t *gui, bag_t *my_bag)
{
	static bool my_event[EVENTS_LEN] = {0};

	gui->my_event = my_event;
	my_event[gui->event.type] = true;
	if (change_stage(0, 0) != 0) {
		call_event_in_map(stage, gui, my_bag);
	}
	else
		call_event_in_menu(stage, gui, my_bag);
	for (int i = 0; i != EVENTS_LEN; i++)
		my_event[i] = false;
}

void run_events(struct gui_s *gui, stage_t *stage
, bag_t *my_bag)
{
	if (gui->event.type == sfEvtClosed) {
		gui->running = false;
		return;
	}
	dispatch_event(stage, gui, my_bag);
}
