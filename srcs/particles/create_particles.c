/*
** E_pITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** create.c
*/

#include "my_rpg.h"
#include "nbr.h"
#include <stdlib.h>
#include <string.h>

particles_t *new_part_buffer(int size)
{
	size_t size_buff = (sizeof(particles_t) + sizeof(sfVertex)
	* size * 4 + sizeof(pixel_t) * size);
	particles_t *buffer;
	void *array = malloc(size_buff);

	if (array == NULL)
		return (NULL);
	memset(array, 0, size_buff);
	buffer = (particles_t *)(array);
	buffer->size = size;
	buffer->vertex = (sfVertex *)(array + sizeof(particles_t));
	buffer->pixel = (pixel_t *)(buffer->vertex + (size * 4));
	return (buffer);
}

void set_part(sfColor color, uint i, gui_t *gui, sfVector2i pos)
{
	int x = ((rand() % 30) + 1);
	int y = ((rand() % 30) + 1);

	pos.x = rand_generate(pos.x - x , pos.x + y);
	pos.y = rand_generate(pos.y - x , pos.y + y);
	gui->particles->vertex[(i * 4) + 0].position = (sfVector2f){(float)pos.x
	+ 0, (float)pos.y + 0};
	gui->particles->vertex[(i * 4) + 1].position = (sfVector2f){(float)pos.x
	+ 3, (float)pos.y + 0};
	gui->particles->vertex[(i * 4) + 2].position = (sfVector2f){(float)pos.x
	+ 3, (float)pos.y + 3};
	gui->particles->vertex[(i * 4) +  3]
	.position = (sfVector2f){(float)pos.x
	+ 0, (float)pos.y + 3};
	gui->particles->vertex[(i * 4) +  0].color = color;
	gui->particles->vertex[(i * 4) + 1].color = color;
	gui->particles->vertex[(i * 4) + 2].color = color;
	gui->particles->vertex[(i * 4) + 3].color = color;
	gui->particles->pixel[i].speed.x = ((float)(rand () % 255) / 255);
	gui->particles->pixel[i].speed.y = ((float)(rand () % 255) / 255);
	gui->particles->pixel[i].life = 1;
}

particles_t *init_particles(gui_t *gui)
{
	gui->particles = new_part_buffer (17);
	sfVector2i pos = {0};

	for (uint i = 0; i != 17; i++)
		set_part(sfBlue, i, gui, pos);
}

uint new_part(particles_t *buffer)
{
	for (uint id = buffer->size - 1; id != 0; id -= 1)
		if (buffer->pixel[id].life <= 0)
			return (id);
	return ((uint)(-1));
}
