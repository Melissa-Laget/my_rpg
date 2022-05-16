/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** update_inventory
*/

#include "draw.h"
#include "actions.h"

static void update_inventory_textures(game_t *game, int y, int x)
{
    int item = 0;

    if ((item = game->menus.inventory.items[y][x]) == NO_ITEM) {
        game->menus.inventory.slots[y][x]->texture = NULL;
        return;
    }
    game->menus.inventory.slots[y][x]->texture =
    game->menus.inventory.texture[game->menus.inventory.items[y][x]];
}

int update_inventory(game_t *game)
{
    for (int y = 0; y < INVENTORY_ROW; y++) {
        for (int x = 0; x < INVENTORY_COL; x++) {
            update_inventory_textures(game, y, x);
        }
    }
    return 0;
}
