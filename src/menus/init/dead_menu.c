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
    "background",
    "respawn",
    "launch_menu",
    "quit_game",
    NULL
};

static const char *views[] = {
    "dead_view",
    NULL
};

int init_dead_menu(game_t *game)
{
    list_t *actions = NULL;

    actions = hud_action_append(actions, "launch_game", &launch_game, game);
    actions = hud_action_append(actions, "launch_menu", &launch_menu, game);
    actions = hud_action_append(actions, "quit_game", &quit_game, game);
    if ((game->menus.dead = hud_init(game->win, actions,
        "assets/hud/dead.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.dead, buttons) ||
        !hud_check_views(game->menus.dead, views))
        return -2;
    return 0;
}
