/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** event.h
*/

#ifndef EVENT_H
#define EVENT_H

void custom_prev(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void custom_next(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void save_game(gui_t *gui, stage_t *stage, bag_t *mybag);
bool load_game(gui_t *gui, stage_t *stage, bag_t *mybag);
void move_player(stage_t *stage, int i);
int check_player_move(stage_t *stage, gui_t *gui);
int handle_event(gui_t *gui, stage_t *stage);
void health_potion(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void handle_keys_bar(stage_t *stage, gui_t *gui, bag_t *my_bag);
void handle_tab(stage_t *stage, gui_t *gui, bag_t *my_bag);
void reset(stage_t *stage, gui_t *gui, bag_t *my_bag);
void unknow(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void change_item_select(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void dispatch_action(stage_t *stage, int id, gui_t *gui, bag_t *my_bag);
void prepare_actions_dictionary(gui_t *gui);
void dispatch_event(stage_t *stage, gui_t *gui, bag_t *my_bag);
void display_inventory(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void display_quests(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void display_stats_action(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void over_button(stage_t *stage, gui_t *gui, bag_t *my_bag);
void close_custom_panel(stage_t *stage);
void handle_custom_player(stage_t *stage, gui_t *gui, bag_t *my_bag);
void print_panel_settings(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void choose_screen_size(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void disable_pause(stage_t *stage, gui_t *gui);
void handle_game_pause(stage_t *stage, gui_t *gui, bag_t *my_bag);
void go_menu(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void print_custom_player(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);

#endif
