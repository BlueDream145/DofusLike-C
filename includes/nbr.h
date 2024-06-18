/*
** EPITECH PROJECT, 2018
** str.h
** File description:
** str
*/

#ifndef NBR_H
#define NBR_H
#include <unistd.h>
#include <stdlib.h>

char *char_to_int(int score);
char *convert_base(int number);
int *associate(char *binary);
int my_put_nbr_d(int nb);
int rand(void);
int my_compute_power_rec(int nb, int p);
int my_base_to_int(char *nbr, char const *base);
int get_index(int i, int change);
int rand_generate(int a , int b);

#endif
