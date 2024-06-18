/*
** EPITECH PROJECT, 2018
** charles.raimbault@epitech.eu
** File description:
** text.c
*/

#include "my_rpg.h"
#include "str.h"

void info_player_to_text(stage_t *stage, gui_t *gui)
{
	sfText_setString(stage->texte[0].text
	, int_to_char(stage->players[0].strength));
	sfText_setString(stage->texte[1].text
	, int_to_char(stage->players[0].level));
	sfText_setString(stage->texte[2].text
	, int_to_char(stage->players[0].stamina));
	sfText_setString(stage->texte[3].text
	, int_to_char(stage->players[0].stamina_max));
	sfText_setString(stage->texte[4].text, gui->custom.name);
}

static int init_text_config(uint num, stage_t *stage
, FILE *fp)
{
	size_t len = 0;
	int len_1 = 0;
	char *buffer = NULL;

	if (getline(&buffer, &len, fp) == -1)
		return (84);
	sfText_setCharacterSize(stage->texte[num].text, my_getnbr(buffer));
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->texte[num].pos.x = my_getnbr(buffer);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	stage->texte[num].pos.y = my_getnbr(buffer);
	sfText_setPosition(stage->texte[num].text,  stage->texte[num].pos);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	return (0);
}

static int inti_string_and_pos(uint num, stage_t *stage
, FILE *fp)
{
	size_t len = 0;
	int len_1 = 0;
	char *buffer = get_first_line(NULL, 0);

	stage->texte[num].text = sfText_create();
	if (buffer == NULL)
		if (getline(&buffer, &len, fp) == -1)
			return (84);
	len_1 = my_strlen(buffer);
	buffer[len_1 - 1] = '\0';
	stage->texte[num].font = sfFont_createFromFile(buffer);
	sfText_setFont(stage->texte[num].text, stage->texte[num].font);
	if (getline(&buffer, &len, fp) == -1)
		return (84);
	sfText_setString(stage->texte[num].text, buffer);
	return (0);
}

int init_text(uint num, stage_t *stage, FILE *fp, gui_t *gui)
{
	if (inti_string_and_pos(num, stage, fp) == 84
	|| init_text_config(num, stage, fp) == 84)
		return (84);
	return (0);
}
