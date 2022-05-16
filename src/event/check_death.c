/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** check_death
*/

#include "rpg.h"
#include "actions.h"

void add_to_inventory_multi(game_t *game, int nb)
{
    for (int i = 0; i < nb; i++)
        append_to_inventory(game, WOOD_ITEM);
    game->npc_death.log += nb;
}

static void check_npc_death(game_t *game)
{
    if (game->npc_death.dead_lumberjack == 1)
        add_to_inventory_multi(game, 1);
    if (game->npc_death.dead_lumberjack == 1)
        game->npc_death.dead_lumberjack = 2;
    if (game->npc_death.dead_morshu == 1)
        add_to_inventory_multi(game, 5);
    if (game->npc_death.dead_morshu == 1)
        game->npc_death.dead_morshu = 2;
    if (game->npc_death.dead_old_man == 1)
        add_to_inventory_multi(game, 7);
    if (game->npc_death.dead_old_man == 1)
        game->npc_death.dead_old_man = 2;
}

void check_death(game_t *game)
{
    check_npc_death(game);
    if (game->npc_death.dead_orc == 1)
        add_to_inventory_multi(game, 1);
    if (game->npc_death.dead_orc == 1)
        game->npc_death.dead_orc = 2;
    if (game->npc_death.dead_villager == 1)
        add_to_inventory_multi(game, 1);
    if (game->npc_death.dead_villager == 1)
        game->npc_death.dead_villager = 2;
    if (game->npc_death.dead_guard == 1)
        add_to_inventory_multi(game, 1);
    if (game->npc_death.dead_guard == 1)
        game->npc_death.dead_guard = 2;
}
