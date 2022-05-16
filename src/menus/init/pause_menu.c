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
    "resume_game", "launch_menu", "quit_game",
    "800", "720", "1080", "mute_settings",
    "background",
    NULL
};

static const char *views[] = {
    "pause_menu",
    NULL
};

int init_pause_menu(game_t *game)
{
    list_t *actions = NULL;

    actions = hud_action_append(actions, "resume_game", &resume_game, game);
    actions = hud_action_append(actions, "launch_menu", &launch_menu, game);
    actions = hud_action_append(actions, "quit_game", &quit_game, game);
    actions = hud_action_append(actions, "resolution_setting",
    &resolution_setting, game);
    actions = hud_action_append(actions, "sound_setting",
    &sound_setting, game);
    if ((game->menus.pause_menu = hud_init(game->win, actions,
        "assets/hud/pause_menu.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.pause_menu, buttons) ||
        !hud_check_views(game->menus.pause_menu, views))
        return -2;
    return 0;
}
