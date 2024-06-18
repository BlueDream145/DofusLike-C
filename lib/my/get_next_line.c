/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** CPE
*/

#include <unistd.h>
#include <stdlib.h>
#include "str.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_backslash_n(char *str)
{
	int i = 0;
	int mod = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n') {
			mod = 1;
			i++;
			break;
		}
		i++;
	}
	if (mod == 0)
		return (0);
	return (i);
}

char *recons(char *buffer , char *result , int to_copy)
{
	int len = 0;
	int i = 0;

	len = my_strlen(result);
	buffer = malloc(sizeof(char) * len + 1);
	while (i != to_copy) {
		buffer[i] = result[i];
		i++;
	}
	buffer[i - 1] = '\0';
	i = 0;
	while (result[to_copy] != '\0') {
		result[i] = result[to_copy];
		i++;
		to_copy++;
	}
	result[i] = '\0';
	return (buffer);
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char) * 1 + 1);

	if (buffer == NULL)
		return (NULL);
	static char *result = NULL;
	static int passage = 0;
	int nbr = read(fd, buffer, 1);
	int to_copy = 0;

	if (nbr < 1)
		return (NULL);
	passage++;
	buffer[nbr] = '\0';
	result = my_strdupcat(result , buffer);
	to_copy = check_backslash_n(result);
	if (to_copy != 0) {
		buffer = recons(buffer , result , to_copy);
		return (buffer);
	}
	get_next_line(fd);
}
