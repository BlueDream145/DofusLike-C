/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** draw_path.c
*/

#include "my_rpg.h"

static void cmp_val(int x, int y, int **map, path_t *path)
{
	if (path->val == 0 || map[y][x] < path->val) {
		path->val = map[y][x];
		path->xcell = x;
		path->ycell = y;
	}
}

void draw_path(int x, int y, int **map, int **path, path_t *info)
{
	path[y][x] = info->num;
	if (map[y][x] == 1)
		return;
	info->num++;
	check_val(x, y, map, info);
	draw_path(info->xcell, info->ycell, map, path, info);
}

void check_val(int x, int y, int **map, path_t *inf)
{
	if (x < inf->w - 1 && map[y][x + 1] > 0)
		cmp_val(x + 1, y, map, inf);
	if (x > 0 && map[y][x - 1] > 0)
		cmp_val(x - 1, y, map, inf);
	if (y < inf->h - 1 && map[y + 1][x] > 0)
		cmp_val(x, y + 1, map, inf);
	if (y > 0 && map[y - 1][x] > 0)
		cmp_val(x, y - 1, map, inf);
	if (x > 0 && y > 0 && map[y - 1][x - 1] > 0)
		cmp_val(x - 1, y - 1, map, inf);
	if (x < inf->w - 1 && y > 0 && map[y - 1][x + 1] > 0)
		cmp_val(x + 1, y - 1, map, inf);
	if (x > 0 && y < inf->h - 1 && map[y + 1][x - 1] > 0)
		cmp_val(x - 1, y + 1, map, inf);
	if (x < inf->w - 1 && y < inf->h - 1 && map[y + 1][x + 1] > 0)
		cmp_val(x + 1, y + 1, map, inf);
}
