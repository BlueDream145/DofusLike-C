/*
** EPITECH PROJECT, 2017
** my_putbinaire
** File description:
** printf
*/

#include <stdlib.h>
#include "str.h"

char *my_printbinaire(int nbr)
{
	int i = 7;
	char *display = malloc(sizeof(char) * 9);
	int result = 0;

	if (display == NULL)
		return (NULL);
	while (nbr != 0) {
		result = nbr % 2;
		display[i] = result + 48;
		nbr = nbr / 2;
		i--;
	}
	display[8] = '\0';
	if (i != -1)
		display[0] = '0';
	return (display);
}
