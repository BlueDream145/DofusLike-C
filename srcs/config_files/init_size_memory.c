/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** init_size_memory.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "str.h"

int verif_malloc(stage_t *stage)
{
	if (stage->sprite == NULL
	|| stage->button == NULL
	|| stage->anim == NULL
	|| stage->order == NULL
	|| stage->texte == NULL
	|| stage->players == NULL)
		return (84);
	return (0);
}

int malloc_struct(stage_t *stage, char **size)
{
	int nbr = my_getnbr(*size) + 1;

	stage->button = malloc(sizeof(button_t) * nbr);
	for (int i = 0; *size[i] >= '0' && *size[i] <= '9'; *size += 1);
	nbr = my_getnbr(*(size + 1)) + 1;
	stage->sprite = malloc(sizeof(sprite_t) * nbr);
	for (int i = 0; *size[i] >= '0' && *size[i] <= '9'; *size += 1);
	nbr = my_getnbr(*(size + 2)) + 1;
	stage->anim = malloc(sizeof(animation_t) * nbr);
	nbr = my_getnbr(*(size + 3)) + 1;
	stage->order = malloc(sizeof(order_t) * nbr);
	stage->nbr_order = nbr - 1;
	nbr = my_getnbr(*(size + 4)) + 1;
	stage->players = malloc(sizeof(players_t) * nbr);
	nbr = my_getnbr(*(size + 5)) + 1;
	stage->texte = malloc(sizeof(text_t) * nbr);
	return (verif_malloc(stage));
}

int init_nbr_element(stage_t *stage, char **size)
{
	stage->nbr_elem[0] = my_strdup(size[0]);
	stage->nbr_elem[1] = my_strdup(size[1]);
	stage->nbr_elem[2] = my_strdup(size[2]);
	stage->nbr_elem[3] = my_strdup(size[3]);
	stage->nbr_elem[4] = my_strdup(size[4]);
	stage->nbr_elem[5] = my_strdup(size[5]);
	if (stage->nbr_elem[0] == NULL
	|| stage->nbr_elem[1] == NULL
	|| stage->nbr_elem[2] == NULL
	|| stage->nbr_elem[3] == NULL
	|| stage->nbr_elem[4] == NULL
	|| stage->nbr_elem[5] == NULL)
		return (84);
	return (0);
}
