/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
** Run graphics
*/

#include "my_rpg.h"
#include "stage.h"
#include "str.h"
#include "sound.h"

void init_utl_map(gui_t *gui, stage_t *stage)
{
	gui->game.shiftx = 0;
	gui->game.shifty = 0;
	gui->game.mx = 0;
	gui->game.my = 0;
	gui->game.map = NULL;
	stage->players[0].x = 0;
	stage->players[0].y = 0;
	stage->players[0].state = 0;
	gui->path.xB = 0;
	gui->path.yB = 0;
	gui->path.w = 0;
	gui->path.h = 0;
	gui->path.xcell = 0;
	gui->path.ycell = 0;
	gui->path.dist = -1;
	gui->path.num = 1;
	gui->path.val = 0;
}

int run_graphic(gui_t *gui)
{
	const int default_fps = 60;
	stage_t *stage = NULL;
	bag_t *my_bag = init_bag();

	gui->win_size = sfRenderWindow_getSize(gui->window);
	stage = check_current_stage(stage, gui);
	if (stage == NULL)
		return (84);
	play_random_music(gui);
	play_music(gui);
	sfWindow_setFramerateLimit((sfWindow*)gui->window, default_fps);
	loop(gui, stage, my_bag);
	return (EXIT_NORMALLY);
}

static void action_no_pause(gui_t *gui, stage_t *stage)
{
	if (gui->pause_mode == false) {
		if (change_stage(0, 0) != 0) {
			check_change_map(stage);
			gen_bot_pos(gui, stage);
			info_player_to_text(stage, gui);
			disp_win(gui, stage);
			check_player_move(stage, gui);
			check_bot_attack(stage, gui);
			handle_questes(stage);
		}
	}
}

static void handle_start_event(gui_t *gui, stage_t *stage
, bag_t *my_bag, sfClock *my_clock)
{
	static int start = false;

	if (start == true) {
		while (sfRenderWindow_pollEvent(gui->window, &gui->event))
			run_events(gui, stage, my_bag);
		return;
	}
	handle_clok_start_anim(&start, my_clock, stage);
}

void loop(gui_t *gui, stage_t *stage, bag_t *my_bag)
{
	sfClock *my_clock = sfClock_create();
	sfVector2i pos = {500, 500};
	if (my_clock == NULL)
		return;
	stage = check_current_stage(stage, gui);
	while (sfRenderWindow_isOpen(gui->window) && gui->running) {
		handle_start_event(gui, stage, my_bag, my_clock);
		stage = check_current_stage(stage, gui);
		if (stage == NULL)
			return;
		draw_graphics(gui, stage, my_bag);
		update_particles(gui, sfYellow
		, sfMouse_getPositionRenderWindow(gui->window));
		action_no_pause(gui, stage);
		sfRenderWindow_display(gui->window);
		sfRenderWindow_clear(gui->window, sfBlack);
	}
}
