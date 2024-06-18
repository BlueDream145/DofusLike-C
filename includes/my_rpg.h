/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Header file of the My RPG project
*/

#ifndef MY_RPG
#define MY_RPG

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include "inventory.h"

#define COS cos(45)
#define SIN sin(34.85)

enum e_func_evt {
	HANDLE_EVT_MAP,
	FIND_CLICK,
	RESET,
	OVER_BUT,
	HANDLE_TAB,
	HANDLE_KEY_BAR,
	HANDLE_GAME_PAUSE,
	HANDLE_CUSTOM_PLAYER,
	NBR_FUNC_EVT
};

enum return_status {
	EXIT_NORMALLY = 0,
	EXIT_FAIL = 84,
	DEFAULT = 0,
};

enum NEXT_MAP {
	MAP_LEFT = 321,
	MAP_RIGHT = 1550,
	MAP_TOP = 0,
	MAP_BOTTOM = 1012,
};

enum window_info {
	ACTIONS_LEN = 5,
	EVENTS_LEN = 22,
	MAP_X = 14,
	MAP_Y = 40,
	SCAL_X = 90,
	SCAL_Y = 90,
	SCREEN_WIDTH = 1920,
	SCREEN_HEIGHT = 1080,
	SCREEN_FPS = 60,
};

typedef unsigned int uint;
typedef struct s_bag bag_t;
typedef struct s_particles particles_t;
typedef struct players_s players_t;
typedef struct gui_s gui_t;
typedef struct s_handle_event handle_event_t;
typedef struct stage_s stage_t;
typedef void (*evt_act_handler)(gui_t *gui, stage_t *stage
, bag_t *my_bag, int id);
typedef void (*go_find_evt)(stage_t *stage, gui_t *gui
, bag_t *my_bag);

#include "path.h"
#include "stage.h"
#include "gui.h"
#include "particles.h"
#include "event.h"

static const char *class_path[] = {"./assets/character/cra/"
, "./assets/character/iop/"
, "./assets/character/sram/"};
static const char *case_male = "male/";
static const char *case_female = "female/";

typedef struct s_handle_event {
	evt_act_handler actions_handlers;
	bool on_off;
} handle_event_t;

typedef handle_event_t *(*ptr_change_evt_stage[])(void);

typedef int (*init_func[])(uint, stage_t *, FILE *, gui_t *);
/* ___________________________DRAW_FUNCTIONS__________________________________*/
void draw_graphics(gui_t *gui, stage_t *stage, bag_t *my_bag);
int print_stage(gui_t *gui, stage_t *stage);
void print_background(stage_t *stage, gui_t *gui);
int disp_win(gui_t *gui, stage_t *stage);

/*____________________________________________________________________________*/

int init_game(stage_t *stage, gui_t *gui);
void free_window_instance(gui_t *gui);
int run_graphic(gui_t *gui);
void loop(gui_t *gui, stage_t *stage, bag_t *my_bag);
void invert_sprite(int scale, stage_t *stage, int i);
void run_events(struct gui_s *gui, stage_t *stage
, bag_t *my_bag);
void gender(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
gui_t *get_window_instance(void);
int check_env(char **env);
void save(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
sfVector2f iso_pnt(int x, int y);
sfVertexArray *create_tile(sfVector2f *tile, sfPrimitiveType type);
int game(gui_t *gui);
int open_create_file(const char *file_name);
char *get_buf(int size);
stage_t *check_current_stage(stage_t *stage, gui_t *gui);
int button_contains_point(sfVector2f *elem_pos, sfVector2f *elem_rect
, int state, sfVector2i *pos);
int element_contains_point(sfVector2f *elem_pos,
sfVector2f *elem_rect, sfVector2f *pos);
int attack_ennemy(stage_t *stage, int i, int key, int loose_life);
/*			Actions / Events				*/
void replace_objet(sfVector2i *replace, int i, int j, bag_t *my_bag);
void give_obj_quest(bag_t *my_bag, int cur_quest);
void fix_pipe(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void pick_up_water(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
int change_quest(int mode, int new_value);
void start_quest(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
int story_chgmt_map(int mode, int new_value);
void check_change_map(stage_t *stage);
void affect_new_pos_player_map(stage_t *stage, gui_t *gui);
void move_item(bag_t *my_bag, gui_t *gui);
void get_case(bag_t *my_bag, sfVector2i *case_find);
void clear_case(bag_t *my_bag);
sfVector2f get_position(const int x, const int y);
void handle_event_map(stage_t *stage, gui_t *gui, bag_t *my_bag);
void find_click_button(stage_t *stage, gui_t *gui, bag_t *my_bag);
sfVector2f *get_tile(int x, int y, gui_t *gui);
int **load_map(char *name, gui_t *gui);
void handle_items(bag_t *my_bag, gui_t *gui);
void handle_scroll_bar(bag_t *my_bag, gui_t *gui);
void check_scale(int dir, stage_t *stage, int i);
char **malloc_tab(FILE *stream, gui_t *gui);
int check_file(char **file);
void simple_attack(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
void reset_map(int **map);
void init_utl_map(gui_t *gui, stage_t *stage);
void gen_bot_pos(gui_t *gui, stage_t *stage);
int init_bot(gui_t *gui, stage_t *stage);
void check_player_attack(gui_t *gui, stage_t *stage);
void check_bot_attack(stage_t *stage, gui_t *gui);
void display_help(gui_t *gui, stage_t *stage, bag_t *my_bag, int id);
int update_value(int to_pass, int reset);
void check_reset_variable(int *j, int *i);
int **convert_map(char **map, gui_t *gui);
int check_tile(int i, int j, gui_t *gui);

#endif
