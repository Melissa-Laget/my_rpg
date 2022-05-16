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
    "strength", "defense", "magic", "health", "fire", "ice",
    "poison", "background",
    NULL
};

static const char *views[] = {
    "stats_menu",
    NULL
};

void init_stats_value(game_t *game, hud_t *hud)
{
    game->stat_text.text_strenght = hud_button_get(hud, "strength")->text;
    game->stat_text.text_defense = hud_button_get(hud, "defense")->text;
    game->stat_text.text_magic = hud_button_get(hud, "magic")->text;
    game->stat_text.text_health = hud_button_get(hud, "health")->text;
    game->stat_text.text_fire = hud_button_get(hud, "fire")->text;
    game->stat_text.text_ice = hud_button_get(hud, "ice")->text;
    game->stat_text.text_poison = hud_button_get(hud, "poison")->text;
}

int init_stats_menu(game_t *game)
{
    list_t *actions = NULL;

    actions = hud_action_append(actions, "resume_game", &resume_game, game);
    if ((game->menus.stats_menu = hud_init(game->win, actions,
        "assets/hud/stats_menu.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.stats_menu, buttons) ||
        !hud_check_views(game->menus.stats_menu, views))
        return -2;
    init_stats_value(game, game->menus.stats_menu);
    return 0;
}
