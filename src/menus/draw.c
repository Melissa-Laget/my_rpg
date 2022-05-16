/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** draw
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void draw_inventory(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    update_inventory(game);
    hud_render(game->menus.inventory_menu);
    sfRenderWindow_setView(game->win, game->view);
}

void draw_pause(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.pause_menu);
    sfRenderWindow_setView(game->win, game->view);
}

void draw_stats(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.stats_menu);
    sfRenderWindow_setView(game->win, game->view);
}

void draw_skill(game_t *game)
{
    sfRenderWindow_setView(game->win, game->win_view);
    hud_render(game->menus.skill_tree_menu);
    sfRenderWindow_setView(game->win, game->view);
}
