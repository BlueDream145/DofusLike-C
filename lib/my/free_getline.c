/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** free_getline.c
*/

#include <stdlib.h>

void *free_getline(char *ptr)
{
	free(ptr);
	return (NULL);
}
