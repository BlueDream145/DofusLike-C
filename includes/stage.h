/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** draw.h
*/

#ifndef STAGE_H
#define STAGE_H

enum menu {
	LOAD_GAME,
	NEW_GAME,
	CUSTOM,
	SETTINGS,
	TRACK_BUTTON,
	EXIT_BUTTON,
	TRACK_SOUND,
	PREV,
	NEXT,
	GENDER,
	BUTTON_1920,
	BUTTON_1680,
	HELP,
	MENU_LEN
};

enum map_one {
	DISPLAY_INVENTORY,
	DISPLAY_QUEST,
	DISPLAY_SAVE,
	Equip_1 = 27,
	Equip_2,
	Equip_3,
	Scrool = 37,
	QUIT_GAME = 38,
	GO_MENU,
	START_QUEST,
	MAP_LEN
};

enum map_three {
	PICK_UP_WATER = 40,
	MAP_THREE_LEN
};

enum map_for {
	FIX_PIPE = 40,
	MAP_FOR_LEN
};

enum stage {
	MENU,
	MAP_ONE,
	NBR_STAGE
};

typedef struct s_button {
	sfTexture *texture;
	sfRectangleShape *Button;
	sfVector2f size;
	int hitbox_button_x;
	int hitbox_button_y;
	sfVector2f position;
	int state;
	sfIntRect RectButton;
} button_t;

typedef struct s_sprite {
	sfSprite *sprite;
	sfTexture *textureSprite;
	sfVector2f positionSprite;
	sfVector2f OriginSprite;
	int state;
} sprite_t;

typedef struct text_s {
	sfText* text;
	sfFont* font;
	int state;
	sfVector2f pos;
} text_t;

typedef struct players_s {
	int stamina;
	int stamina_max;
	int level;
	int strength;
	sfVector2f new;
	sfVector2i start_case;
	int x;
	int y;
	int state;
	int **path;
	sfClock *clock;
	sfClock *c_attack;
	int agro;
} players_t;

typedef struct animation_s {
	sfClock *clock;
	sfTime time;
	float time_sec;
	sfIntRect rect;
	sfSprite *sprite;
	sfTexture *anim_texture;
	sfVector2f position;
	int delay;
	sfVector2f anim_origin;
	sfVector2i image_size;
	int advance;
	int state;
	int way;
	int dir;
} animation_t;

typedef struct order_s {
	int type;
	int num;
} order_t;

typedef struct stage_s {
	char *nbr_elem[6];
	int next_scene[3];
	sfVector2i ref[3];
	sfVector2i spawn[3];
	sprite_t *sprite;
	button_t *button;
	animation_t *anim;
	order_t *order;
	int nbr_order;
	text_t *texte;
	players_t *players;
} stage_t;

int handle_clok_start_anim(int *start, sfClock *my_clock, stage_t *stage);
int change_stage(int mode, int new_value);
void handle_questes(stage_t *stage);
int init_button(uint num, stage_t *stage, FILE * fp, gui_t *gui);
int init_sprite(uint num, stage_t *stage, FILE *fp, gui_t *gui);
int init_animation(uint num, stage_t *stage, FILE *fp, gui_t *gui);
int init_order(uint num, stage_t *stage, FILE *fp, gui_t *gui);
int init_players(uint num, stage_t *stage, FILE *fp, gui_t *gui);
int init_text(uint num, stage_t *stage, FILE *fp, gui_t *gui);
void check_anim(stage_t *stage, int i);
void info_player_to_text(stage_t *stage, gui_t *gui);
int handle_start_stage(int num_stage, stage_t *stage, gui_t *gui);
int malloc_struct(stage_t *stage, char **size);
int init_change_stage(FILE *fp, stage_t *stage, gui_t *gui);
int init_size_animation(uint num, stage_t *stage, FILE * fp);
void apply_rect_animation(stage_t *stage , int i);
int init_anim_origin(stage_t *stage, int i, FILE *fp);
int init_rect_animation(uint num, stage_t *stage, FILE * fp);
int init_pos_animation(uint num, stage_t *stage, FILE * fp);
int init_nbr_element(stage_t *stage, char **size);
int check_comment_file(char *buffer);

#endif
