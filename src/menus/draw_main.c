/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** draw_main
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void draw_main_menu(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.main_menu);
    sfRenderWindow_setView(game->win, game->view);
}

void draw_main_hud(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.hud);
    sfRenderWindow_setView(game->win, game->view);
}

void draw_dead(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.dead);
    sfRenderWindow_setView(game->win, game->view);
}

void event_dead(game_t *game)
{
    hud_event(game->menus.dead);
}
