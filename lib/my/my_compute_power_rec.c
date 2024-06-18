/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** Power by recursion
*/

int my_compute_power_rec(int nb, int p)
{
	int res = 0;
	if (p == 0) {
		return (1);
	}
	if (p < 0) {
		return (0);
	}
	res = (my_compute_power_rec(nb, p - 1) * nb);
	return (res);
}
