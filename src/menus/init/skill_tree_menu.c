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
    "resume_game", "fire", "ice", "poison", "magic", "strength",
    "defense", "background",
    NULL
};

static const char *views[] = {
    "skill_tree",
    NULL
};

int init_skill_tree_menu(game_t *game)
{
    list_t *actions = NULL;

    actions = hud_action_append(actions, "resume_game", &resume_game, game);
    actions = hud_action_append(actions, "fire", &unlock_fire, game);
    actions = hud_action_append(actions, "ice", &unlock_ice, game);
    actions = hud_action_append(actions, "poison", &unlock_poison, game);
    actions = hud_action_append(actions, "magic", &unlock_magic, game);
    actions = hud_action_append(actions, "strength", &upgrade_strength, game);
    actions = hud_action_append(actions, "defense", &upgrade_defense, game);
    if ((game->menus.skill_tree_menu = hud_init(game->win, actions,
        "assets/hud/skill_tree.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.skill_tree_menu, buttons) ||
        !hud_check_views(game->menus.skill_tree_menu, views))
        return -2;
    return 0;
}
