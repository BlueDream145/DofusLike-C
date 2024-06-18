/*
** EPITECH PROJECT, 2018
** libmy.a
** File description:
** compare two strings until n characters
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	for (; i < n && s1[i] != '\0' && s2 [i] != '\0'; i++) {
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
	}
	if (s1[i] < s2[i])
		return (-1);
	else if (s1[i] > s2[i])
		return (1);
	return (0);
}
