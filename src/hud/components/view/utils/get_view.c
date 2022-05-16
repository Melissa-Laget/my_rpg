/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** get_view
*/

#include "hud.h"

hud_view_t *hud_view_get(hud_t *hud, const char *name)
{
    for (list_t *tmp = hud->all_views; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((hud_view_t *)tmp->data)->name, name) == 0)
            return ((hud_view_t *)tmp->data);
    }
    return NULL;
}
