/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** display a str
*/

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
