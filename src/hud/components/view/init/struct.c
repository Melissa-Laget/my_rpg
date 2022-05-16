/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** struct
*/

#include "hud.h"

hud_view_t *hud_view_init(void)
{
    hud_view_t *view = malloc(sizeof(hud_view_t));

    view->name = NULL;
    view->pos = ((sfIntRect){.left = 0, .top = 0,
    .width = 200, .height = 200});
    view->hidden = false;
    view->border = true;
    view->borderWidth = ((sfFloatRect){.left = 5, .top = 5,
    .width = 5, .height = 5});
    view->borderColor = sfBlack;
    view->color = sfWhite;
    view->texture = NULL;
    view->views = NULL;
    view->buttons = NULL;
    return view;
}
