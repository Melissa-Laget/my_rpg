/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** pos
*/

#include "hud.h"
#include <SFML/Graphics.h>

void hud_view_set_pos(hud_view_t *view, int x, int y)
{
    view->pos.left = x;
    view->pos.top = y;
}

void hud_view_set_size(hud_view_t *view, int x, int y)
{
    view->pos.width = x;
    view->pos.height = y;
}
