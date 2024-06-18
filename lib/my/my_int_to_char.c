/*
** EPITECH PROJECT, 2018
** int_to_str
** File description:
** lib
*/

#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int my_int_len(int score)
{
	int i = 1;

	while (score != 0) {
		i++;
		score = score / 10;
	}
	return (i);
}

char *int_to_char(int score)
{
	int i = my_int_len(score);
	char *str = malloc(sizeof(char) * (i + 1));

	if (score == 0) {
		str[0] = '0';
		str[1] = '\0';
	}
	i = 0;
	while (score != 0) {
		str[i] = (score % 10) + 48;
		i++;
		score = score / 10;
		if (score == 0)
			str[i] = '\0';
	}
	str = my_revstr(str);
	return (str);
}
