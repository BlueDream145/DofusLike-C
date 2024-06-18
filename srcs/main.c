/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Main function of the My RPG project
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "sound.h"
#include <fcntl.h>
#include <unistd.h>
#include "str.h"

int save_player_name(int ac, char **av, gui_t *gui)
{
	if (ac != 2) {
		my_putstr("A real hero have a name !!!\n");
		return (EXIT_FAIL);
	}
	else {
		gui->custom.name = my_strdup(av[1]);
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int fd = open("/dev/random", O_RDONLY);
	gui_t *gui;
	int callback = EXIT_NORMALLY;

	if (check_env(envp) == 1)
		return (84);
	if (fd != -1) {
		read(fd, &fd, 1);
		srand(fd);
	}
	gui = get_window_instance();
	sfRenderWindow_setMouseCursorVisible(gui->window, sfFalse);
	if (gui == NULL || save_player_name(ac, av, gui) == EXIT_FAIL)
		return (EXIT_FAIL);
	callback = run_graphic(gui);
	stop_music(gui);
	free(gui);
	return (callback);
}
