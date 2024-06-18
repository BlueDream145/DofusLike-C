/*
** EPITECH PROJECT, 2017
** rand
** File description:
** runner
*/

#include <stdlib.h>

int rand_generate(int a , int b)
{
	return (rand() % (b - a) + a);
}
