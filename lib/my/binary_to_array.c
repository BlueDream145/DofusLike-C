/*
** EPITECH PROJECT, 2018
** base
** File description:
** lib
*/

#include <stdlib.h>
#include "str.h"

int *associate(char *binary)
{
	char temp[3];
	int *info_param = malloc(sizeof(int) * 4);
	int j = 0;

	if (info_param == NULL)
		return (NULL);
	for (int i = 0; j < 4;) {
		temp[0] = binary[i];
		temp[1] = binary[i + 1];
		temp[2] = '\0';
		info_param[j] = my_getnbr(temp);
		i += 2;
		j++;
	}
	return (info_param);
}
