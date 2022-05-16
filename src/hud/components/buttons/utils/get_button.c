/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** get_button
*/

#include "hud.h"

hud_button_t *hud_button_get(hud_t *hud, const char *name)
{
    for (list_t *tmp = hud->all_buttons; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((hud_button_t *)tmp->data)->name, name) == 0)
            return ((hud_button_t *)tmp->data);
    }
    return NULL;
}
