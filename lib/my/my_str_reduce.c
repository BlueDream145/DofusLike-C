/*
** EPITECH PROJECT, 2018
** my_str_reduce
** File description:
** my_str_reduce.c
*/

int my_str_reduce(char *str, char c)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			str[i] = '\0';
	}
	return (0);
}
