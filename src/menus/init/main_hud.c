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

static const char *buttons[] = {
    "health_box",
    NULL
};

static const char *views[] = {
    "health",
    "stats",
    NULL
};

int init_main_hud(game_t *game)
{
    list_t *actions = NULL;

    if ((game->menus.hud = hud_init(game->win, actions,
    "assets/hud/hud.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.hud, buttons) ||
        !hud_check_views(game->menus.hud, views))
        return -2;
    return 0;
}
