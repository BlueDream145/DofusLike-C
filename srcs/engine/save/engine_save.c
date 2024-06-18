/*
** EPITECH PROJECT, 2018
** engine_save.c
** File description:
** Save
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "my_rpg.h"

static const char *data_filename = "save.dat";

void save_game(gui_t *gui, stage_t *stage, bag_t *mybag)
{
	int fd = open(data_filename, O_APPEND | O_CREAT
		| O_TRUNC | O_WRONLY, 0666);

	if (fd <= 0)
		return;
	write(fd, gui, sizeof(gui));
	write(fd, mybag, sizeof(mybag));
	close(fd);
}

bool load_game(gui_t *gui, stage_t *stage, bag_t *mybag)
{
	int fd = open(data_filename, O_RDONLY);

	if (fd <= 0)
		return (false);
	read(fd, gui, sizeof(gui));
	read(fd, mybag, sizeof(mybag));
	close(fd);
	return (true);
}

int open_create_file(const char *file_name)
{
	int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 00664);

	if (fd <= 0)
		return (-1);
	return (fd);
}