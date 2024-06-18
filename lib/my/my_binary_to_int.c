/*
** EPITECH PROJECT, 2018
** libmy.a
** File description:
** convert a binary into an int
*/

#include "str.h"
#include "nbr.h"

int nb_in_base(char digit, char const *base)
{
	for (int i = 0; base[i] != '\0'; i++) {
		if (digit == base[i])
			return (i);
	}
	return (-1);
}

int my_base_to_int(char *nbr, char const *base)
{
	int len = my_strlen(nbr);
	int len_base = my_strlen(base);
	int res = 0;

	my_revstr(nbr);
	for (int i = 0; i < len; i++) {
		res += (my_compute_power_rec(len_base, i) *
			nb_in_base(nbr[i], base));
	}
	return (res);
}
