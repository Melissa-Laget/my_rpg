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
    "launch_game", "settings", "quit_game",
    "800", "720", "1080",
    "mute_settings", "back_settings",
    "how_to_play", "how_to_play_button",
    "game_title",
    NULL
};

static const char *views[] = {
    "main_menu", "settings_view",
    NULL
};

int init_main_menu(game_t *game)
{
    list_t *actions = NULL;

    actions = hud_action_append(actions, "launch_game", &launch_game, game);
    actions = hud_action_append(actions, "settings", &launch_settings, game);
    actions = hud_action_append(actions, "quit_settings", &quit_settings, game);
    actions = hud_action_append(actions, "quit_game", &quit_game, game);
    actions = hud_action_append(actions, "resolution_setting",
    &resolution_setting, game);
    actions = hud_action_append(actions, "sound_setting",
    &sound_setting, game);
    actions = hud_action_append(actions, "how_to_play",
    &how_to_play, game);
    if ((game->menus.main_menu = hud_init(game->win, actions,
        "assets/hud/main_menu.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.main_menu, buttons) ||
        !hud_check_views(game->menus.main_menu, views))
        return -2;
    return 0;
}
