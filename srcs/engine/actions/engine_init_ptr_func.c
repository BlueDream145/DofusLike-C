/*
** EPITECH PROJECT, 2018
** engine_actions.c
** File description:
** engine_actions
*/

#include "my_rpg.h"
#include <stdlib.h>

static handle_event_t *assign_function_to_button(handle_event_t *handle_event)
{
	handle_event[LOAD_GAME].actions_handlers = load_game_action;
	handle_event[NEW_GAME].actions_handlers = new_game_action;
	handle_event[CUSTOM].actions_handlers = settings;
	handle_event[SETTINGS].actions_handlers = print_panel_settings;
	handle_event[TRACK_BUTTON].actions_handlers = trackbutton;
	handle_event[EXIT_BUTTON].actions_handlers = exit_button;
	handle_event[TRACK_SOUND].actions_handlers = tracksound;
	handle_event[CUSTOM].actions_handlers = print_custom_player;
	handle_event[PREV].actions_handlers = custom_prev;
	handle_event[NEXT].actions_handlers = custom_next;
	handle_event[GENDER].actions_handlers = gender;
	handle_event[BUTTON_1920].actions_handlers = choose_screen_size;
	handle_event[BUTTON_1680].actions_handlers = choose_screen_size;
	handle_event[HELP].actions_handlers = display_help;
	return (handle_event);
}

handle_event_t *init_evt_menu(void)
{
	handle_event_t *handle_event;

	handle_event = malloc(sizeof(handle_event_t) * MENU_LEN);
	if (handle_event == NULL)
		return (NULL);
	for (int i = 0; i != MENU_LEN; i++)
		handle_event[i].on_off = 0;
	handle_event = assign_function_to_button(handle_event);
	return (handle_event);
}

handle_event_t *init_evt_map_one(void)
{
	handle_event_t *handle_event;

	handle_event = malloc(sizeof(handle_event_t) * MAP_LEN);
	if (handle_event == NULL)
		return (NULL);
	for (int i = 0; i != MAP_LEN; i++)
		handle_event[i].on_off = false;
	handle_event[DISPLAY_INVENTORY].actions_handlers = display_inventory;
	handle_event[DISPLAY_QUEST].actions_handlers = display_quests;
	handle_event[DISPLAY_SAVE].actions_handlers = unknow;
	for (int i = 3; i != Equip_1; i++)
		handle_event[i].actions_handlers = change_item_select;
	for (int i = Equip_1; i != MAP_LEN; i++)
		handle_event[i].actions_handlers = unknow;
	handle_event[Equip_3 + 1].actions_handlers = health_potion;
	handle_event[Equip_3 + 7].actions_handlers = simple_attack;
	handle_event[QUIT_GAME].actions_handlers = exit_button;
	handle_event[GO_MENU].actions_handlers = go_menu;
	handle_event[START_QUEST].actions_handlers = start_quest;
	return (handle_event);
}

handle_event_t *init_evt_map_three(void)
{
	handle_event_t *handle_event;

	handle_event = malloc(sizeof(handle_event_t) * MAP_THREE_LEN);
	if (handle_event == NULL)
		return (NULL);
	for (int i = 0; i != MAP_THREE_LEN; i++)
		handle_event[i].on_off = false;
	handle_event[DISPLAY_INVENTORY].actions_handlers = display_inventory;
	handle_event[DISPLAY_QUEST].actions_handlers = display_quests;
	handle_event[DISPLAY_SAVE].actions_handlers = save;
	for (int i = 3; i != Equip_1; i++)
		handle_event[i].actions_handlers = change_item_select;
	for (int i = Equip_1; i != MAP_THREE_LEN; i++)
		handle_event[i].actions_handlers = unknow;
	handle_event[Equip_3 + 1].actions_handlers = health_potion;
	handle_event[Equip_3 + 7].actions_handlers = simple_attack;
	handle_event[QUIT_GAME].actions_handlers = exit_button;
	handle_event[GO_MENU].actions_handlers = go_menu;
	handle_event[PICK_UP_WATER].actions_handlers = pick_up_water;
	return (handle_event);
}

handle_event_t *init_evt_map_four(void)
{
	handle_event_t *handle_event;

	handle_event = malloc(sizeof(handle_event_t) * MAP_THREE_LEN);
	if (handle_event == NULL)
		return (NULL);
	for (int i = 0; i != MAP_FOR_LEN; i++)
		handle_event[i].on_off = false;
	handle_event[DISPLAY_INVENTORY].actions_handlers = display_inventory;
	handle_event[DISPLAY_QUEST].actions_handlers = display_quests;
	handle_event[DISPLAY_SAVE].actions_handlers = save;
	for (int i = 3; i != Equip_1; i++)
		handle_event[i].actions_handlers = change_item_select;
	for (int i = Equip_1; i != MAP_FOR_LEN; i++)
		handle_event[i].actions_handlers = unknow;
	handle_event[Equip_3 + 1].actions_handlers = health_potion;
	handle_event[Equip_3 + 7].actions_handlers = simple_attack;
	handle_event[QUIT_GAME].actions_handlers = exit_button;
	handle_event[GO_MENU].actions_handlers = go_menu;
	handle_event[FIX_PIPE].actions_handlers = fix_pipe;
	return (handle_event);
}
