/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** check_next_position.c
*/

#include "my_rpg.h"
#include "str.h"

static int set_player_pos(int x, int y, gui_t *gui, players_t *player)
{
	int num = player->path[y][x] - 1;
	sfVector2f *tile = NULL;

	if (num > 0 && y < 39 && player->path[y + 1][x] == num)
		y += 1;
	else if (num > 0 && y > 0 && player->path[y - 1][x] == num)
		y -= 1;
	tile = get_tile(x, y, gui);
	if (tile == NULL)
		return (-1);
	player->new.x = (int)tile[2].x;
	player->new.y = (int)tile[3].y;
	player->x = x;
	player->y = y;
	return (1);
}

static int check_side_pos(int x, int y, gui_t *gui, players_t *player)
{
	int num = player->path[y][x];

	if (x < 13 && player->path[y][x + 1] == num - 1)
		return (set_player_pos(x + 1, y, gui, player));
	if (x > 0 && player->path[y][x - 1] == num - 1)
		return (set_player_pos(x - 1, y, gui, player));
	if (y < 39 && player->path[y + 1][x] == num - 1)
		return (set_player_pos(x, y + 1, gui, player));
	if (y > 0 && player->path[y - 1][x] == num - 1)
		return (set_player_pos(x, y - 1, gui, player));
	return (0);
}

static int check_diag_pos(int x, int y, gui_t *gui, players_t *player)
{
	int num = player->path[y][x];

	if (x > 0 && y > 0 && player->path[y - 1][x - 1] == num - 1)
		return (set_player_pos(x - 1, y - 1, gui, player));
	if (x < 13 && y > 0 && player->path[y - 1][x + 1] == num - 1)
		return (set_player_pos(x + 1, y - 1, gui, player));
	if (x > 0 && y < 39 && player->path[y + 1][x - 1] == num - 1)
		return (set_player_pos(x - 1, y + 1, gui, player));
	if (x < 13 && y < 39 && player->path[y + 1][x + 1] == num - 1)
		return (set_player_pos(x + 1, y + 1, gui, player));
	return (0);
}

static int check_next_pos(int x, int y, gui_t *gui, players_t *player)
{
	int ret = 0;
	int num = player->path[y][x];

	if (num == 1) {
		if (player->state == 1) {
			player->state = 0;
			return (1);
		}
		return (0);
	}
	ret = check_side_pos(x, y, gui, player);
	if (ret == 0)
		check_diag_pos(x, y, gui, player);
	if (ret == -1)
		return (-1);
	return (0);
}

int check_player_move(stage_t *stage, gui_t *gui)
{
	int i = 0;

	while (i != my_getnbr(stage->nbr_elem[4])) {
		if (stage->anim[i].state != 0
		&& stage->anim[i].position.x == stage->players[i].new.x
		&& stage->anim[i].position.y == stage->players[i].new.y) {
			check_next_pos(stage->players[i].x, \
				stage->players[i].y, gui, &stage->players[i]);
		}
		else if (stage->anim[i].state != 0){
			stage->players[i].state = 1;
			move_player(stage, i);
		}
		i++;
	}
}
