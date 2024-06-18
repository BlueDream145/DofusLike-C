/*
** EPITECH PROJECT, 2017
** my_char_isalpha_num.c
** File description:
** char_is_alpha.c
*/

int my_char_isalpha_num(char alpha)
{
	if ((alpha > 64 && alpha < 91) || (alpha > 96 && alpha < 123) || \
	(alpha < 58 && alpha > 47) || alpha == '-' || alpha == '/' || \
	alpha == '_' || alpha == '.')
		return (1);
	else
		return (0);
}
