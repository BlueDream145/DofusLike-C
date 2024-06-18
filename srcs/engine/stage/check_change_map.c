/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
** Run graphics
*/

#include "my_rpg.h"

int story_chgmt_map(int mode, int new_value)
{
	static int value = -1;

	if (mode == 1)
		value = new_value;
	return (value);
}

void affect_new_pos_player_map(stage_t *stage, gui_t *gui)
{
	if (story_chgmt_map(0, 0) == -1)
		return;

	sfVector2f *tile = get_tile(stage->spawn[story_chgmt_map(0, 0)].x
	, stage->spawn[story_chgmt_map(0, 0)].y, gui);

	if (tile == NULL)
		return;
	stage->anim[0].position.x = (int)tile[2].x;
	stage->anim[0].position.y = (int)tile[3].y;
	stage->players[0].new.x = stage->anim[0].position.x;
	stage->players[0].new.y = stage->anim[0].position.y;
	stage->players[0].x = stage->spawn[story_chgmt_map(0, 0)].x;
	stage->players[0].y = stage->spawn[story_chgmt_map(0, 0)].y;
}

static void affect_change_map(stage_t *stage, int i)
{
	change_stage(1, stage->next_scene[i]);
	story_chgmt_map(1, i);
}

void check_change_map(stage_t *stage)
{
	for (int i = 0; i != 3; i++) {
		if ((stage->ref[i].x == 0 && stage->ref[i].y == 0)
		|| stage->next_scene[i] == 0)
			continue;
		if (stage->anim[0].position.x >= stage->ref[i].x - 30
		&& stage->anim[0].position.x <= stage->ref[i].x  + 30
		&& stage->ref[i].y == 0)
			affect_change_map(stage, i);
		else if (stage->anim[0].position.y >= stage->ref[i].y - 30
		&& stage->anim[0].position.y <= stage->ref[i].y  + 30
		&& stage->ref[i].x == 0)
			affect_change_map(stage, i);
		else if (stage->anim[0].position.x >= stage->ref[i].x - 30
		&& stage->anim[0].position.x <= stage->ref[i].x  + 30
		&& stage->anim[0].position.y >= stage->ref[i].y - 30
		&& stage->anim[0].position.y <= stage->ref[i].y  + 30)
			affect_change_map(stage, i);
	}
}
