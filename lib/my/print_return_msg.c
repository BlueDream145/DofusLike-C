/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** print_return_msg.c
*/

#include "str.h"

int return_with_msg(int value, char *msg)
{
	my_putstr(msg);
	return (value);
}
