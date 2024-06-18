/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** particles.h
*/

#ifndef PARTICLES_H
#define PARTICLES_H

typedef struct s_pixel pixel_t;

typedef struct s_particles
{
	sfVertex* vertex ;
	uint size ;
	pixel_t *pixel;
	sfColor color;
} particles_t;

typedef struct s_pixel
{
	sfVector2f speed;
	float life;
} pixel_t ;

void update_part_buffer (particles_t *buffer);
particles_t *init_particles(gui_t *gui);
void update_particles(gui_t *gui, sfColor color, sfVector2i);
uint new_part(particles_t *buffer);
void set_part(sfColor color, uint i, gui_t *gui, sfVector2i);

#endif
