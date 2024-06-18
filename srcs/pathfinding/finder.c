/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** finder.c
*/

#include "my_rpg.h"

static void get_dist(int xA, int yA, path_t *info, int cost)
{
	int x = info->xB - xA;
	int y = info->yB - yA;
	int dist = 0;

	if (x < 0)
		x = x * (-1);
	if (y < 0)
		y = y * (-1);
	dist = x + y + cost;
	if (info->dist == -1 || dist < info->dist) {
		info->dist = dist;
		info->dist = dist;
		info->xcell = xA;
		info->ycell = yA;
	}
}

static void get_short_dist(int **map, int x, int y, path_t *info)
{
	if (x < info->w - 1 && map[y][x + 1] == 0)
		get_dist(x + 1, y, info, 10);
	if (x > 0 && map[y][x - 1] == 0)
		get_dist(x - 1, y, info, 10);
	if (y < info->h - 1 && map[y + 1][x] == 0)
		get_dist(x, y + 1, info, 10);
	if (y > 0 && map[y - 1][x] == 0)
		get_dist(x, y - 1, info, 10);
	if (x > 0 && y > 0 && map[y - 1][x - 1] == 0)
		get_dist(x - 1, y - 1, info, 14);
	if (x < info->w - 1 && y > 0 && map[y - 1][x + 1] == 0)
		get_dist(x + 1, y - 1, info, 14);
	if (x > 0 && y < info->h - 1 && map[y + 1][x - 1] == 0)
		get_dist(x - 1, y + 1, info, 14);
	if (x < info->w - 1 && y < info->h - 1 && map[y + 1][x + 1] == 0)
		get_dist(x + 1, y + 1, info, 14);
}

static int check_around(int **map, int x, int y, path_t *info)
{
	if (x < info->w - 1 && map[y][x + 1] == 0
	|| x > 0 && map[y][x - 1] == 0
	|| y < info->h - 1 && map[y + 1][x] == 0
	|| y > 0 && map[y - 1][x] == 0
	|| x > 0 && y > 0 && map[y - 1][x - 1] == 0
	|| x < info->w - 1 && y > 0 && map[y - 1][x + 1] == 0
	|| x > 0 && y < info->h - 1 && map[y + 1][x - 1] == 0
	|| x < info->w - 1 && y < info->h - 1 && map[y + 1][x + 1] == 0)
		return (1);
	return (0);
}

int finder(int **map, int x, int y, path_t *info)
{
	do {
		if (x == info->xB && y == info->yB) {
			map[y][x] = info->num;
			return (1);
		}
		get_short_dist(map, x, y, info);
		if (info->dist == -1) {
			map[y][x] = info->num;
			info->num--;
			return (0);
		}
		info->dist = -1;
		map[y][x] = info->num;
		info->num += 1;
		if (finder(map, info->xcell, info->ycell, info) == 1)
			return (1);
	} while (check_around(map, x, y, info) == 1);
	info->num--;
	return (0);
}
