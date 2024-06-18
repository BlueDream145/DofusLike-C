/*
** EPITECH PROJECT, 2018
** engine_stage_handler.c
** File description:
** handler current stage
*/

#include <stdlib.h>
#include "my_rpg.h"

static stage_t *get_new_stage(int num_stage, gui_t *gui, stage_t *stage)
{
	stage_t *new_stage = malloc(sizeof(stage_t));

	if (handle_start_stage(num_stage, new_stage, gui) == 84)
		return (NULL);
	return (new_stage);
}

int change_stage(int mode, int new_value)
{
	static int value = 0;

	if (mode == 1)
		value = new_value;
	return (value);
}

static int update_event(gui_t *gui, int index_stage)
{
	static ptr_change_evt_stage change_evt_stage
	= {init_evt_menu, init_evt_map_one, init_evt_map_one
	, init_evt_map_three, init_evt_map_four, init_evt_map_one};

	gui->handle_event = change_evt_stage[index_stage]();
	if (gui->handle_event == NULL)
		return (84);
	return (0);
}

stage_t *check_current_stage(stage_t *stage, gui_t *gui)
{
	static int crt_stage = 1;

	if (crt_stage == change_stage(DEFAULT, DEFAULT))
		return (stage);
	else {
		crt_stage = change_stage(DEFAULT, DEFAULT);
		if (stage != NULL)
			free(stage);
		stage = get_new_stage(crt_stage, gui, stage);
		if (stage == NULL)
			return (NULL);
		update_event(gui, crt_stage);
		return (stage);
	}
}
