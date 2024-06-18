/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** split a string in array of word
*/


#include <stdio.h>
#include <stdlib.h>
#include "nbr.h"
#include "str.h"

char **affect(int size, char **tab, char *to_parse, int count)
{
	*tab = to_parse;
	for (int i = 0, j = 1; i < size - 1; i++ , to_parse++) {
		if (j != count + 2 && *to_parse == '\0') {
			tab[j] = to_parse + 1;
			j++;
		}
	}
	tab[count + 1] = NULL;
	return (tab);
}

char **my_str_to_word_array(char *str)
{
	str = my_strdup(str);
	if (str == NULL)
		return (NULL);
	char **tab;
	char *to_parse = str;
	int size = my_strlen(to_parse);
	int count = 0;

	for (; *to_parse != '\0'; to_parse++) {
		if (*to_parse == '-' || *to_parse == ' ') {
			*to_parse = '\0';
			count++;
		}
	}
	tab = malloc(sizeof(char *) * (count + 2));
	if (tab == NULL)
		return (NULL);
	to_parse = str;
	return (affect(size, tab, to_parse, count));
}
