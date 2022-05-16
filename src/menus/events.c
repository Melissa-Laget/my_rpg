/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** main_menu
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void event_main_menu(game_t *game)
{
    hud_event(game->menus.main_menu);
}

void event_inventory(game_t *game, sfEvent *event __attribute__((unused)))
{
    hud_event(game->menus.inventory_menu);
}

void event_pause(game_t *game)
{
    hud_event(game->menus.pause_menu);
}

void event_stats(game_t *game)
{
    hud_event(game->menus.stats_menu);
}

void event_skill(game_t *game)
{
    hud_event(game->menus.skill_tree_menu);
}
