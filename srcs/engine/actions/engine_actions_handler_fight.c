/*
** EPITECH PROJECT, 2018
** engine_actions_handler_fight.c
** File description:
** Fight
*/

#include "my_rpg.h"

void simple_attack(gui_t *gui, stage_t *stage, bag_t *my_bag, int id)
{
	int dmg = 10 + stage->players[0].strength;

	if (gui->my_event[sfEvtMouseButtonPressed] == false)
		return;
	if (stage->players[0].stamina > 0)
	stage->players[0].stamina -= dmg;
}
