/*
** EPITECH PROJECT, 2018
** my_array_dup
** File description:
** lib
*/

#include <stdlib.h>
#include "str.h"

char **my_array_dup(char **map)
{
	int array_len = my_array_len(map) + 1;
	char **dup = malloc(sizeof(char *) * array_len);
	int i = 0;

	if (dup == NULL)
		return (NULL);
	while (map[i] != NULL) {
		dup[i] = my_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
