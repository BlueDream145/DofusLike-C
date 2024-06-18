/*
** EPITECH PROJECT, 2018
** engine_stage_draw.c
** File description:
** print current stage
*/

#include <time.h>

#include "my_rpg.h"
#include "str.h"
#include "sound.h"

static void print_sprite(stage_t *stage, struct gui_s *gui, int i)
{
	if (stage->sprite[i].state == 0)
		return;
	sfRenderWindow_drawSprite(gui->window, stage->sprite[i].sprite, NULL);
}

static void print_button(stage_t *stage, struct gui_s *gui, int i)
{
	if (stage->button[i].state == 0)
		return;
	sfRenderWindow_drawRectangleShape(gui->window, stage->button[i]
	.Button, NULL);
}

static void print_animation_back(stage_t *stage, struct gui_s *gui, int i)
{
	static int mouv = 0;

	if (stage->anim[i].state == 0)
		return;
	stage->anim[i].time = sfClock_getElapsedTime(stage->anim[i].clock);
	stage->anim[i].time_sec = sfTime_asMilliseconds(stage->anim[i].time);
	if (stage->anim[i].time_sec > stage->anim[i].delay) {
		if (stage->anim[i].rect.left >= stage->anim[i].image_size.x)
			mouv = 1;
		else if (stage->anim[i].rect.left <= 0)
			mouv = 0;
		if (mouv == 0)
			stage->anim[i].rect.left += stage->anim[i].advance;
		else if (mouv == 1)
			stage->anim[i].rect.left -= stage->anim[i].advance;
		sfSprite_setTextureRect(stage->anim[i].sprite, \
			stage->anim[i].rect);
		sfClock_restart(stage->anim[i].clock);
	}
}

static void print_animation(stage_t *stage, struct gui_s *gui, int i)
{
	if (stage->anim[i].state == 0)
		return;
	sfRenderWindow_drawSprite(gui->window, stage->anim[i].sprite, NULL);
	if (change_stage(0, 0) != 0 && stage->players[i].state == 0) {
		stage->anim[i].rect.left = 0;
		sfSprite_setTextureRect(stage->anim[i].sprite, \
		stage->anim[i].rect);
		return;
	}
	stage->anim[i].time = sfClock_getElapsedTime(stage->anim[i].clock);
	stage->anim[i].time_sec = sfTime_asMilliseconds(stage->anim[i].time);
	if (stage->anim[i].time_sec > stage->anim[i].delay) {
		if (stage->anim[i].rect.left >= stage->anim[i].image_size.x)
			stage->anim[i].rect.left = stage->anim[i].advance;
		else
			stage->anim[i].rect.left += stage->anim[i].advance;
		sfSprite_setTextureRect(stage->anim[i].sprite, \
		stage->anim[i].rect);
		sfClock_restart(stage->anim[i].clock);
	}
}

int print_stage(struct gui_s *gui, stage_t *stage)
{
	static void (*draw_fun[])(stage_t *, gui_t *, int) = {&print_button
	, &print_sprite, &print_animation};
	sfClock *elapsed = sfClock_create();

	if (gui->fps == 0)
		gui->fps++;
	while (sfTime_asMicroseconds(sfClock_getElapsedTime(elapsed))
		<= (60000 / gui->fps));
	sfClock_restart(elapsed);
	for (int order = 0; order != stage->nbr_order; order++)
		draw_fun[stage->order[order].type]
		(stage, gui, stage->order[order].num);
	for (int i = 0; i != my_getnbr(stage->nbr_elem[5]); i++) {
		sfRenderWindow_drawText(gui->window
		, stage->texte[i].text, NULL);
	}
	return (0);
}
