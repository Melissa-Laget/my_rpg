/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** skill_tree
*/

#include "event.h"
#include "actions.h"

void unlock_magic(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    if (game->skill_tree.defense >= 1 && game->skill_tree.strength >= 1
        && game->npc_death.log >= 2 && game->skill_tree.unlock_magic != 1) {
        game->skill_tree.unlock_magic = 1;
        game->npc_death.log -= 2;
        del_from_inventory(game, WOOD_ITEM);
        del_from_inventory(game, WOOD_ITEM);
    }
}
