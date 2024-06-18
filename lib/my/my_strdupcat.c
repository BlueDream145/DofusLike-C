/*
** EPITECH PROJECT, 2018
** strdupcat
** File description:
** lib
*/

#include "str.h"
#include <stdlib.h>

char *my_strdupcat(char *str1 , char *str2)
{
	int len = my_strlen(str2);
	int i = 0;

	if (str1 != NULL)
		len += my_strlen(str1);
	char *dest = malloc(sizeof(char) * (len + 1));

	if (dest == NULL)
		return (NULL);
	if (str1 != NULL)
		while (str1[i] != '\0') {
			dest[i] = str1[i];
			i++;
		}
	for (int j = 0; str2[j] != '\0'; j++) {
		dest[i] = str2[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
