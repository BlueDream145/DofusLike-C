/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
	int i = 0;
	char temp = 0;

	while (str[i])
		i++;
	i--;
	for (int j = 0; j < i; j++) {
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i--;
	}
	return (str);
}
