/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** check_buttons
*/

#include "hud.h"

bool hud_check_buttons(hud_t *hud, const char **buttons_name)
{
    if (buttons_name == NULL)
        return false;
    for (int i = 0; buttons_name[i] != NULL; i++) {
        if (hud_button_get(hud, buttons_name[i]) == NULL)
            return false;
    }
    return true;
}

bool hud_check_views(hud_t *hud, const char **views_name)
{
    if (views_name == NULL)
        return false;
    for (int i = 0; views_name[i] != NULL; i++) {
        if (hud_view_get(hud, views_name[i]) == NULL)
            return false;
    }
    return true;
}
