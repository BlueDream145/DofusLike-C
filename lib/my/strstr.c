/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** my_strstr.c
*/

#include <unistd.h>
#include <stdlib.h>

int count(char const *str, char const *to_find)
{
	int j = 0;
	int activ = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == to_find[j] || activ == 1) {
			j = j + 1;
			activ = 1;
		}
	}
	return (j);
}

char *my_strstr(char const *str, char const *to_find)
{
	int j = 0;
	int activ = 0;
	char *find = malloc(sizeof(char) * count(str, to_find) + 1);

	if (find == NULL)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == to_find[j] || activ == 1) {
			find[j] = str[i];
			activ = 1;
			j++;
		}
	}
	find[j] = '\0';
	return (find);
}
