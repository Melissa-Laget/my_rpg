/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw
*/

#include "hud.h"

void hud_render_buttons(hud_t *hud, list_t *buttons, sfVector2f view_pos)
{
    while (buttons != NULL) {
        hud_button_render(hud->win, ((hud_button_t *)buttons->data), view_pos);
        buttons = buttons->next;
    }
}

void hud_render_views(hud_t *hud, list_t *views, sfVector2f view_pos)
{
    sfVector2f new_pos;

    for (; views != NULL; views = views->next) {
        if (((hud_view_t *)views->data)->hidden == true)
            continue;
        hud_view_render(hud->win, ((hud_view_t *)views->data), view_pos);
        new_pos.x = ((hud_view_t *)views->data)->pos.left + view_pos.x;
        new_pos.y = ((hud_view_t *)views->data)->pos.top + view_pos.y;
        hud_render_buttons(hud, ((hud_view_t *)views->data)->buttons, new_pos);
        hud_render_views(hud, ((hud_view_t *)views->data)->views, new_pos);
    }
}

void hud_render(hud_t *hud)
{
    hud_render_buttons(hud, hud->buttons, ((sfVector2f){.x = 0, .y = 0}));
    hud_render_views(hud, hud->views, ((sfVector2f){.x = 0, .y = 0}));
}
