/*
** EPITECH PROJECT, 2018
** isnum
** File description:
** lib
*/

int is_num(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
