/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** update_particles.c
*/

#include "my_rpg.h"
#include <string.h>

void update_particles(gui_t *gui, sfColor color, sfVector2i pos)
{
	uint id = 0;

	for (int i = 0; i < 10; i += 1) {
		id = new_part(gui->particles) ;
		if ( id == (uint)(-1))
			break;
		set_part(color, i, gui, pos);
	}
	update_part_buffer(gui->particles);
	sfRenderWindow_drawPrimitives(gui->window, gui->particles->vertex
	, gui->particles->size * 4, sfQuads, NULL);
}

void update_part_buffer (particles_t *buffer)
{
	for (uint id = 0; id < buffer->size ; id += 1) {
		buffer->vertex[(id * 4) + 0].color.a
		= (int)(buffer->pixel[id].life * 255);
		buffer->vertex[(id * 4) + 1].color.a
		= (int)(buffer->pixel[id].life * 255);
		buffer->vertex[(id * 4) + 2].color.a
		= (int)(buffer->pixel[id].life * 255);
		buffer->vertex[(id * 4) + 3].color.a
		= (int)(buffer->pixel[id].life * 255);
		if (buffer->pixel[id].life <= 0)
			continue;
		buffer->pixel[id].life -= 0.1;
		if (buffer->pixel[id].life <= 0) {
			memset(buffer->vertex + (id * 4), 0
			, sizeof(sfVertex) * 4);
			continue;
		}
	}
}
