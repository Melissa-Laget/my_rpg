/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** potion_magic_skill
*/

#include "event.h"
#include "actions.h"

void unlock_fire(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.defense >= 1 &&
        game->skill_tree.strength >= 1 && game->skill_tree.unlock_magic == 1
        && game->npc_death.log >= 1 && game->skill_tree.fire_ball != 1) {
        game->skill_tree.fire_ball = 1;
        game->npc_death.log -= 1;
        del_from_inventory(game, WOOD_ITEM);
    }
}

void unlock_ice(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.defense >= 1 &&
        game->skill_tree.strength >= 1 && game->skill_tree.unlock_magic == 1
        && game->npc_death.log >= 1 && game->skill_tree.ice_ball != 1) {
        game->skill_tree.ice_ball = 1;
        game->npc_death.log -= 1;
        del_from_inventory(game, WOOD_ITEM);
    }
}

void unlock_poison(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.defense >= 1 &&
        game->skill_tree.strength >= 1 && game->skill_tree.unlock_magic == 1
        && game->npc_death.log >= 1 && game->skill_tree.poison_ball != 1) {
        game->skill_tree.poison_ball = 1;
        game->npc_death.log -= 1;
        del_from_inventory(game, WOOD_ITEM);
    }
}
