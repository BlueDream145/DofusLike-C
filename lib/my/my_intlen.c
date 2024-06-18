/*
** EPITECH PROJECT, 2018
** intlen
** File description:
** lib
*/

int my_int_len(int score)
{
	int i = 1;

	while (score != 0) {
		i++;
		score = score / 10;
	}
	return (i);
}
