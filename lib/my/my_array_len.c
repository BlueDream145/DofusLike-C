/*
** EPITECH PROJECT, 2018
** my_array_len
** File description:
** lib
*/

#include <stdlib.h>
#include "str.h"

int my_array_len(char **array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}
