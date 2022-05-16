/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** hud_events
*/

#include "draw.h"
#include "event.h"

static hud_view_t **life_view(void)
{
    static hud_view_t *view;

    return &view;
}

void set_hud_player_hp(game_t *game, int hp)
{
    if (*life_view() == NULL)
        *life_view() = hud_view_get(game->menus.hud, "health");
    (*life_view())->pos.width = (hp >= 0) ? hp * 20 : 0;
}

void init_hud_value(void)
{
    *life_view() = NULL;
}
