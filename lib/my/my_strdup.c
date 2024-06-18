/*
** EPITECH PROJECT, 2018
** strdup
** File description:
** lib
*/

#include <stdlib.h>
#include "str.h"

char *my_strdup(char const *src)
{
	int len = my_strlen(src);
	char *final = malloc(sizeof(char) * len + 1);

	if (final == NULL)
		return (NULL);
	int i = 0;

	while (src[i] != '\0') {
		final[i] = src[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
