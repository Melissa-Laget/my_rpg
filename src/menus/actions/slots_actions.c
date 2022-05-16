/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** slots_actions
*/

#include "draw.h"

bool append_to_inventory(game_t *game, int item)
{
    int y = 0;
    int x = 0;

    while (y < INVENTORY_ROW) {
        if (game->menus.inventory.items[y][x] == NO_ITEM) {
            game->menus.inventory.items[y][x] = item;
            return true;
        }
        x++;
        if (x > INVENTORY_COL) {
            x = 0;
            y++;
        }
    }
    return false;
}

bool del_from_inventory(game_t *game, int item)
{
    int y = 0;
    int x = 0;

    while (y < INVENTORY_ROW) {
        if (game->menus.inventory.items[y][x] == item) {
            game->menus.inventory.items[y][x] = NO_ITEM;
            return true;
        }
        x++;
        if (x > INVENTORY_COL) {
            x = 0;
            y++;
        }
    }
    return false;
}
