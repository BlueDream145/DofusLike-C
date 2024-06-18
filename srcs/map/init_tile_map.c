/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** game functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my_rpg.h"

sfVector2f *get_tile(int x, int y, gui_t *gui)
{
	int i = 0;
	int j = 0;
	int k = 0;
	sfVector2f *t = NULL;

	if ((t = malloc(sizeof(sfVector2f) * 4)) == NULL)
		return (NULL);
	for (j = 0; j != 2; j++) {
		for (i = 0; i != 2; i += 1, k += 1) {
			t[k] = iso_pnt(i * SCAL_X, j * SCAL_Y);
			t[k].x += gui->win_size.x / 2
			- (gui->game.shiftx * 7
			+ gui->game.shiftx / 4)
			+ (gui->game.shiftx / 2
			+ x * gui->game.shiftx
			+ (y % 2) * gui->game.shiftx / 2);
			t[k].y += gui->game.shifty
			+ y * gui->game.shifty / 2;
		}
	}
	return (t);
}

sfVertexArray *create_tile(sfVector2f *tile, sfPrimitiveType type)
{
	sfVertexArray *v_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = tile[0], .color = sfWhite};
	sfVertex vertex2 = {.position = tile[1], .color = sfWhite};
	sfVertex vertex3 = {.position = tile[3], .color = sfWhite};
	sfVertex vertex4 = {.position = tile[2], .color = sfWhite};
	sfVertex vertex5 = {.position = tile[0], .color = sfWhite};

	if (v_array == NULL)
		return (NULL);
	sfVertexArray_append(v_array, vertex1);
	sfVertexArray_append(v_array, vertex2);
	sfVertexArray_append(v_array, vertex3);
	sfVertexArray_append(v_array, vertex4);
	sfVertexArray_append(v_array, vertex5);
	sfVertexArray_setPrimitiveType(v_array, type);
	return (v_array);
}
