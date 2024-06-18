/*
** EPITECH PROJECT, 2017
** getnbr.c
** File description:
** convert av to a number
*/

#include "str.h"

static int neg(char const *str)
{
	int	check = 1;
	int	i = 0;

	while (str[i]) {
		if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0')
			check *= -1;
		else if (str[i] <= '9' && str[i] >= '0')
			break;
		++i;
	}
	return (check);
}

int my_getnbr(char const *str)
{
	int	i = 0;
	int	nb = 0;
	int	count = 0;

	if (my_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while (str[i] && (!(str[i] >= '0' && str[i] <= '9')))
		++i;
	nb = str[i] - 48;
	++i;
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + str[i] - 48;
		++count;
		++i;
	}
	if (count >= 10)
		return (0);
	if (neg(str) < 0)
		nb *= -1;
	return ((nb < 0) ? -1 : nb);
}
