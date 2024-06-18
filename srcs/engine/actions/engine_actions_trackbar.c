/*
** EPITECH PROJECT, 2018
** engine_actions_trackbar
** File description:
** Actions trackbar
*/

#include "my_rpg.h"

static const int track_size = 500;
static const int track_len = 40;

void display_help(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	stage->sprite[9].state = 1;
}

static void get_trackbar_pos(gui_t *gui, stage_t *stage, int order, int index)
{
	if (gui->event.mouseMove.x < 700 || gui->event.mouseMove.x > 1200)
		return;
	if (order == 0)
		stage->button[index].position =
			get_position(gui->event.mouseMove.x
			- track_len, stage->button[index].position.y);
	else
		stage->button[index].position =
			get_position(gui->event.mouseMove.x
			+ track_len, stage->button[index].position.y);
}

static bool track_clicked(gui_t *gui, int clicked)
{
	if (gui->my_event[sfEvtMouseButtonPressed] && !clicked)
		return (true);
	else if (gui->my_event[sfEvtMouseButtonPressed] && clicked)
		return (false);
	return (clicked);
}

void trackbutton(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	static int origin = 700;
	static int order = 1;
	static int clicked = false;
	int purcent = 100;

	clicked = track_clicked(gui, clicked);
	if (!gui->my_event[sfEvtMouseMoved] || !clicked)
		return;
	if (origin == 0)
		origin = stage->button[TRACK_BUTTON].position.x;
	get_trackbar_pos(gui, stage, order, TRACK_BUTTON);
	if (stage->button[TRACK_BUTTON].position.x >=
		origin + track_size - track_len)
		order = 0;
	else if (stage->button[TRACK_BUTTON].position.x <= origin)
		order = 1;
	sfRectangleShape_setPosition(stage->button[TRACK_BUTTON].Button,
		stage->button[TRACK_BUTTON].position);
	purcent = (int)((stage->button[TRACK_BUTTON].position.x - origin)
		/ track_size * 100);
	gui->fps = purcent;
}

void tracksound(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	static int origin = 700;
	static int order = 0;
	static int clicked = false;
	int purcent = 100;

	clicked = track_clicked(gui, clicked);
	if (!gui->my_event[sfEvtMouseMoved] || !clicked)
		return;
	if (origin == 0)
		origin = stage->button[TRACK_SOUND].position.x;
	get_trackbar_pos(gui, stage, order, TRACK_SOUND);
	if (stage->button[TRACK_SOUND].position.x >=
		origin + track_size - track_len)
		order = 0;
	else if (stage->button[TRACK_SOUND].position.x <= origin)
		order = 1;
	sfRectangleShape_setPosition(stage->button[TRACK_SOUND].Button,
		stage->button[TRACK_SOUND].position);
	purcent = (int)((stage->button[TRACK_SOUND].position.x - origin)
		/ track_size * 100);
	sfMusic_setVolume(gui->music, (float)purcent);
}
