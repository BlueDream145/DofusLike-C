/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** look if 2 files are equal
*/

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int diff = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i = i + 1;
	diff = s1[i] - s2[i];
	return (diff);
}
