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

int init_huds(game_t *game)
{
    if (init_main_menu(game) != 0)
        return -1;
    if (init_main_hud(game) != 0)
        return -2;
    if (init_inventory(game) != 0)
        return -3;
    if (init_pause_menu(game) != 0)
        return -4;
    if (init_stats_menu(game) != 0)
        return -5;
    if (init_skill_tree_menu(game) != 0)
        return -6;
    if (init_dead_menu(game) != 0)
        return -7;
    return 0;
}
