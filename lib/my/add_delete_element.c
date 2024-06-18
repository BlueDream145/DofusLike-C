/*
** EPITECH PROJECT, 2017
** add_new_element.c
** File description:
** add an element to a list
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "error.h"

circular_dll_t *create_list(void)
{
	circular_dll_t *root = malloc(sizeof(*root));

	if (root != NULL) {
		root->data = NULL;
		root->go_to[LEFT] = root;
		root->go_to[RIGHT] = root;
	}
	return (root);
}

void delete_element(circular_dll_t **element)
{
	element[0]->go_to[LEFT]->go_to[RIGHT] = element[0]->go_to[RIGHT];
	element[0]->go_to[RIGHT]->go_to[LEFT] = element[0]->go_to[LEFT];
	circular_dll_t *to_free = element[0];

	element[0] = element[0]->go_to[LEFT];
	free(to_free);
}

int add_back(circular_dll_t *element, void *new_data)
{
	circular_dll_t *new_element = malloc(sizeof(*new_element));

	if (new_element == NULL)
		return (PROGRAM_ERROR);
	if (new_element != NULL) {
		new_element->data = new_data;
		new_element->go_to[LEFT] = element->go_to[LEFT];
		new_element->go_to[RIGHT] = element;
		element->go_to[LEFT]->go_to[RIGHT] = new_element;
		element->go_to[LEFT] = new_element;
	}
	return (0);
}
