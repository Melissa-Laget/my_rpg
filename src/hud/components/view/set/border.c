/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** border_size
*/

#include "hud.h"

void hud_view_set_border_size(hud_view_t *view, sfFloatRect borderWidth)
{
    view->borderWidth = borderWidth;
}
