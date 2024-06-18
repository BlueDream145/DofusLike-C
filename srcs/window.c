/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** Set / Free window instance
*/

#include <stdlib.h>
#include "my_rpg.h"

static const char *mouse_sheet = "./assets/gui/mouse_sheet.png";

int init_cursor(gui_t *gui)
{
	gui->cursor.Button = sfRectangleShape_create();
	gui->cursor.texture = sfTexture_createFromFile(mouse_sheet, NULL);
	if (gui->cursor.texture == NULL || gui->cursor.Button == NULL)
		return (84);
	gui->cursor.RectButton.left = 0;
	gui->cursor.RectButton.top = 0;
	gui->cursor.size.x = 23;
	gui->cursor.RectButton.width = 23;
	gui->cursor.size.y = 32;
	gui->cursor.RectButton.height = 32;
	gui->cursor.position.x = 0;
	gui->cursor.position.y = 0;
	gui->cursor.state = 1;
	sfRectangleShape_setTexture(gui->cursor.Button, gui->cursor.texture, 0);
	sfRectangleShape_setSize(gui->cursor.Button, gui->cursor.size);
	sfRectangleShape_setPosition(gui->cursor.Button, gui->cursor.position);
	sfRectangleShape_setTextureRect(gui->cursor.Button
	, gui->cursor.RectButton);
	return (0);
}

void init_value_gui(gui_t *gui)
{
	init_particles(gui);
	gui->custom.sex = 0;
	gui->custom.classe = 0;
	gui->running = true;
	gui->sound = true;
	gui->pause_mode = false;
	gui->fps = 60;
}

gui_t *get_window_instance(void)
{
	gui_t *gui = malloc(sizeof(gui_t));
	sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, 32};

	if (gui == NULL)
		return (NULL);
	gui->window = sfRenderWindow_create(mode, "My_Rpg",
		sfResize | sfFullscreen | sfClose, NULL);
	gui->running = true;
	for (int i = 0; i != NBR_FUNC_EVT; i++)
		gui->detect_evt[i] = true;
	sfRenderWindow_setFramerateLimit(gui->window, SCREEN_FPS);
	prepare_actions_dictionary(gui);
	init_value_gui(gui);
	if (init_cursor(gui) == 84)
		return (NULL);
	sfRenderWindow_setMouseCursorVisible(gui->window, sfFalse);
	return (gui);
}

void free_window_instance(gui_t *gui)
{
	if (gui->event_handlers != NULL)
		free(gui->event_handlers);
	if (gui->window != NULL)
		free(gui->window);
	free(gui);
}
