/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_stats
*/

#include "event.h"
#include "rpg.h"
#include "actions.h"

void upgrade_strength(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.strength == 0 && game->npc_death.log >= 1) {
        game->skill_tree.strength = 1;
        game->npc_death.log -= 1;
        del_from_inventory(game, WOOD_ITEM);
        return;
    }
    if (game->skill_tree.strength == 1 && game->npc_death.log >= 2) {
        game->skill_tree.strength = 2;
        game->npc_death.log -= 2;
        del_from_inventory(game, WOOD_ITEM);
        del_from_inventory(game, WOOD_ITEM);
    }
}

void upgrade_defense(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.defense == 0 && game->npc_death.log >= 1) {
        game->skill_tree.defense = 1;
        game->npc_death.log -= 1;
        del_from_inventory(game, WOOD_ITEM);
        return;
    }
    if (game->skill_tree.defense == 1 && game->npc_death.log >= 2) {
        game->skill_tree.defense = 2;
        game->npc_death.log -= 2;
        del_from_inventory(game, WOOD_ITEM);
        del_from_inventory(game, WOOD_ITEM);
    }
}
