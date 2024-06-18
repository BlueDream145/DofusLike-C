/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_button
*/

#include <stdio.h>
#include "gui.h"
#include "str.h"

static int head_item(FILE * fp, item_t *my_items
, uint num, char *buffer)
{
	size_t len = 0;
	int len_1 = 0;

	if (buffer == NULL) {
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	}
	len_1 = my_strlen(buffer);
	buffer[len_1 - 1] = '\0';
	my_items[num].Button = sfRectangleShape_create();
	if (my_items[num].Button == NULL)
		return (84);
	my_items[num].texture = sfTexture_createFromFile(buffer, NULL);
	if (my_items[num].texture == NULL)
		return (84);
	return (0);
}

static int apply_function_for_rect(item_t *my_items, int i)
{
	sfRectangleShape_setTexture(my_items[i].Button
	, my_items[i].texture, 0);
	sfRectangleShape_setSize(my_items[i].Button
	, my_items[i].size);
	sfRectangleShape_setPosition(my_items[i].Button
	, my_items[i].position);
	sfRectangleShape_setTextureRect(my_items[i].Button
	, my_items[i].RectButton);
	return (0);
}

static int init_size_origin_item(uint num, item_t *my_items, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	my_items[num].RectButton.left = 0;
	my_items[num].RectButton.top = 0;
	my_items[num].size.x = my_getnbr(buffer);
	my_items[num].RectButton.width = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	my_items[num].size.y = my_getnbr(buffer);
	my_items[num].RectButton.height = my_getnbr(buffer);
	return (0);
}

static int init_pos_item(uint num, item_t *my_items, FILE * fp)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	my_items[num].position.x = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	my_items[num].position.y = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	my_items[num].state = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	return (0);
}

item_t *init_item(void)
{
	item_t *my_items;
	char *buffer = NULL;
	size_t len = 0;
	FILE *fp;

	fp = fopen("config_files/items.txt", "r");
	if (fp == NULL)
		return (NULL);
	if (getline(&buffer, &len, fp) == 84)
		return (NULL);
	my_items = malloc(sizeof(item_t) * (my_getnbr(buffer) + 1));
	for (uint num = 0; getline(&buffer, &len, fp) != -1; num++) {
		if (head_item(fp, my_items, num, buffer) == 84
		|| init_size_origin_item(num, my_items, fp) == 84
		|| init_pos_item(num, my_items, fp) == 84)
			return (NULL);
		apply_function_for_rect(my_items, num);
	}
	return (my_items);
}
