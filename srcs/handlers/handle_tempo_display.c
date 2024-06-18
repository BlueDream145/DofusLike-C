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
#include "str.h"

static int draw_tile(gui_t *gui, int i, int j)
{
	sfVector2f *tile = NULL;
	sfVertexArray *v_array = NULL;
	sfPrimitiveType type;

	if (gui->game.map[j][i] == 0)
		type = sfLinesStrip;
	else
		type = sfQuads;
	if ((tile = get_tile(i, j, gui)) == NULL)
		return (-1);
	if ((v_array = create_tile(tile, type)) == NULL)
		return (-1);
	sfRenderWindow_drawVertexArray(gui->window, v_array, NULL);
	return (0);
}

static int draw_map(gui_t *gui)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	for (j = 0; j != MAP_Y && ret == 0; j++) {
		for (i = 0; i != MAP_X && ret == 0; i++) {
			ret = draw_tile(gui, i, j);
		}
	}
	return (ret);
}

static void disp_player(gui_t *gui, stage_t *stage, int i)
{
	sfVector2f pos_p = {stage->anim[i].position.x + 45
	, stage->anim[i].position.y - 130};

	sfSprite_setPosition(stage->anim[i].sprite, pos_p);
}

int disp_win(gui_t *gui, stage_t *stage)
{
	int i = 0;

	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0)
			disp_player(gui, stage, i);
		i++;
	}
	return (0);
}
