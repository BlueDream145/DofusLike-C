/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** gui.h
*/


#ifndef GUI_H
#define GUI_H

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "my_rpg.h"

typedef struct s_button button_t;
typedef struct s_path path_t;

typedef struct s_game
{
	float shiftx;
	float shifty;
	int mx;
	int my;
	int **map;
} game_t;

typedef struct s_custom
{
	char *name;
	int classe;
	int sex;
} custom_t;

struct gui_s {
	evt_act_handler event_handlers[EVENTS_LEN];
	handle_event_t *handle_event;
	sfRenderWindow *window;
	sfMusic *music;
	sfEvent event;
	int sound;
	int fps;
	bool running;
	bool pause_mode;
	bool *my_event;
	int detect_evt[NBR_FUNC_EVT];
	sfVector2u win_size;
	path_t path;
	game_t game;
	int fight_mode;
	particles_t *particles;
	button_t cursor;
	custom_t custom;
	char *path_map;
};

void settings(gui_t *gui, stage_t *stage
, bag_t *my_bag, int id);
void setings_sound(gui_t *gui, stage_t *stage
, bag_t *my_bag, int id);
void load_game_action(gui_t *gui, stage_t *stage
, bag_t *my_bag, int id);
void new_game_action(gui_t *gui, stage_t *stage
, bag_t *my_bag, int id);
void trackbutton(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void tracksound(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void exit_button(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void display_inventory_action(gui_t *gui
, stage_t *stage, bag_t *my_bag, int id);
handle_event_t *init_evt_menu(void);
handle_event_t *init_evt_map_one(void);
handle_event_t *init_evt_map_three(void);
handle_event_t *init_evt_map_four(void);

#endif
