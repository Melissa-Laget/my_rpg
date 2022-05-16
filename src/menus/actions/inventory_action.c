/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** main_menus_action
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "actions.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void toggle_inventory(hud_button_t *button __attribute__((unused)), void *param)
{
    hud_t *inventory = ((game_t *)param)->menus.inventory_menu;
    hud_view_t *inventory_view = NULL;
    hud_view_t *inventory_bar_view = NULL;

    if (sfClock_getElapsedTime(((game_t *)param)->menus.inventory.inventory_wait
        ).microseconds < 50000)
        return;
    sfClock_restart(((game_t *)param)->menus.inventory.inventory_wait);
    inventory_view = hud_view_get(inventory, "inventory");
    inventory_bar_view = hud_view_get(inventory, "inventory_bar");
    if (inventory_view->hidden) {
        inventory_view->hidden = false;
        inventory_bar_view->pos.top = 400;
    } else {
        inventory_view->hidden = true;
        inventory_bar_view->pos.top = 540;
    }
}

hud_button_t **selected_slot(void)
{
    static hud_button_t *selected_button_ptr;

    return &selected_button_ptr;
}

static void move_slot_item(game_t *game, char **new_name, char **old_name)
{
    int new_nbrs[2] = {0, 0};
    int old_nbrs[2] = {0, 0};
    int tmp = -1;

    new_nbrs[1] = my_getnbr(new_name[0]);
    new_nbrs[0] = my_getnbr(new_name[1]);
    old_nbrs[1] = my_getnbr(old_name[0]);
    old_nbrs[0] = my_getnbr(old_name[1]);
    tmp = game->menus.inventory.items[new_nbrs[0]][new_nbrs[1]];
    game->menus.inventory.items[new_nbrs[0]][new_nbrs[1]] =
    game->menus.inventory.items[old_nbrs[0]][old_nbrs[1]];
    game->menus.inventory.items[old_nbrs[0]][old_nbrs[1]] = tmp;
    free_arr((void **)new_name);
    free_arr((void **)old_name);
}

void inventory_slot_action(hud_button_t *button , void *param)
{
    game_t *game = ((game_t *)param);
    char **new_name = NULL;
    char **old_name = NULL;

    if (*selected_slot() == NULL) {
        *selected_slot() = button;
        return;
    }
    if (*selected_slot() == button || (*selected_slot())->texture == NULL) {
        *selected_slot() = button;
        return;
    }
    new_name = str_to_array(button->name, "-");
    old_name = str_to_array((*selected_slot())->name, "-");
    move_slot_item(game, new_name, old_name);
    *selected_slot() = NULL;
}
