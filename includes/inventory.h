/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** inventory.h
*/

#ifndef INVENT_H
#define INVENT_H

typedef struct s_bag bag_t;

typedef struct s_item {
	sfTexture *texture;
	sfRectangleShape *Button;
	sfVector2f size;
	int hitbox_button_x;
	int hitbox_button_y;
	sfVector2f position;
	int state;
	sfIntRect RectButton;
} item_t;

typedef struct s_case {
	int item;
	int moving;
} case_t;

struct s_bag {
	int scroll_select;
	case_t my_case[6][4];
	item_t *my_items;
	int equiped[3];
	sfVector2i ref_case[6][4];
	sfVector2i ref_equip[3];
	sfVector2i ref_scrl_bar[2][4];
};

item_t *init_item(void);
bag_t *init_bag(void);

#endif
