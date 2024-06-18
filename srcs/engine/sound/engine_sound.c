/*
** EPITECH PROJECT, 2017
** my_window_music.c
** File description:
**
*/

#include "my_rpg.h"
#include "sound.h"

static const char *music_path = "./assets/sound/music-1.ogg";

void play_random_music(struct gui_s *gui)
{
	if (gui->sound == false)
		return;
	gui->music = sfMusic_createFromFile(music_path);
	sfMusic_play(gui->music);
	sfMusic_setLoop(gui->music, sfTrue);
}

void mute_music(struct gui_s *gui)
{
	if (gui->sound == true)
		gui->sound = false;
	else
		gui->sound = true;
}

void play_music(struct gui_s *gui)
{
	if (gui->music == NULL) {
		play_random_music(gui);
		return;
	}
	if (gui->sound == false)
		return;
	sfMusic_play(gui->music);
}

void pause_music(struct gui_s *gui)
{
	if (gui->music == NULL || gui->sound == false)
		return;
	sfMusic_pause(gui->music);
}

void stop_music(struct gui_s *gui)
{
	if (gui->music == NULL)
		return;
	if (gui->sound != false)
		sfMusic_stop(gui->music);
	sfMusic_destroy(gui->music);
}