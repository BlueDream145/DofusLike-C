/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Pathfinding header file
*/

#ifndef PATH_H_
#define PATH_H_

enum position {
	RIGHT = 1,
	LEFT = 2,
	FACE = 0,
	DIAG_F,
	SIDE,
	DIAG_B,
	BACK,
};

typedef struct s_path
{
	int xB;
	int yB;
	int w;
	int h;
	int xcell;
	int ycell;
	int dist;
	int num;
	int val;
} path_t;

typedef struct s_pos
{
	sfVector2f lef;
	sfVector2f rig;
	sfVector2f top;
	sfVector2f bot;
} t_pos;

int finder(int **map, int x, int y, path_t *a);
void draw_path(int x, int y, int **map, int **path, path_t *a);
void check_val(int x, int y, int **map, path_t *a);
int **malloc_path(void);
int pathfinding(gui_t *gui, players_t *player);

#endif
