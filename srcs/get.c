/*
** EPITECH PROJECT, 2018
** get.c
** File description:
** get
*/

#include "my_rpg.h"

sfVector2f get_position(const int x, const int y)
{
	sfVector2f vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
