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
    "0-0", "1-0", "2-0", "3-0", "4-0", "5-0",
    "0-1", "1-1", "2-1", "3-1", "4-1", "5-1",
    "0-2", "1-2", "2-2", "3-2", "4-2", "5-2",
    "0-3", "1-3", "2-3", "3-3", "4-3", "5-3",
    "toogle_inventory", "pause",
    NULL
};

static const char *views[] = {
    "inventory",
    "inventory_bar",
    "inventory_slots",
    NULL
};

static const char *items_filepaths[] = {
    "assets/elements_outside/one_log.png",
    NULL
};

sfTexture **init_texture_array(const char **filepaths)
{
    int size = my_tabl_len((void **)filepaths);
    sfTexture **textures = malloc(sizeof(sfTexture *) * (size + 1));

    if (!textures)
        return NULL;
    for (int i = 0; filepaths[i] != NULL; i++) {
        if (!(textures[i] = hud_texture_set(filepaths[i])))
            return NULL;
    }
    textures[size] = NULL;
    return textures;
}

int init_inventory_slots(game_t *game, char *view_name)
{
    hud_view_t *view = hud_view_get(game->menus.inventory_menu,
    view_name);
    char **tmp_str;
    int nbrs[2] = {0, 0};

    if (view == NULL || view->buttons == NULL)
        return -1;
    for (list_t *tmp = view->buttons; tmp != NULL; tmp = tmp->next) {
        if (!(tmp_str = str_to_array(((hud_button_t *)tmp->data)->name, "-")))
            return -2;
        if ((nbrs[1] = my_getnbr(tmp_str[0])) < 0 || nbrs[1] > INVENTORY_COL ||
            (nbrs[0] = my_getnbr(tmp_str[1])) < 0  || nbrs[0] > INVENTORY_COL)
            return -3;
        free_arr((void **)tmp_str);
        game->menus.inventory.slots[nbrs[0]][nbrs[1]] = tmp->data;
    }
    *selected_slot() = NULL;
    return 0;
}

int init_inventory_struct(game_t *game)
{
    if (!(game->menus.inventory.texture = init_texture_array(items_filepaths)))
        return -1;
    if (!(game->menus.inventory.items = malloc(
        sizeof(int *) * (INVENTORY_ROW + 1))))
        return -2;
    if (!(game->menus.inventory.slots = malloc(
        sizeof(hud_button_t **) * (INVENTORY_ROW + 1))))
        return -3;
    for (int i = 0; i < INVENTORY_ROW; i++) {
        if (!(game->menus.inventory.items[i] = malloc(
            sizeof(int) * INVENTORY_COL)) || !(game->menus.inventory.slots[i]
            = malloc(sizeof(hud_button_t *) * INVENTORY_COL)))
            return -4;
        for (int j = 0; j < INVENTORY_COL; j++) {
            game->menus.inventory.items[i][j] = NO_ITEM;
            game->menus.inventory.slots[i][j] = NULL;
        }
    }
    game->menus.inventory.items[INVENTORY_ROW] = NULL;
    return 0;
}

int init_inventory(game_t *game)
{
    list_t *actions = hud_action_append(NULL, "toggle_inventory",
    &toggle_inventory, game);

    actions = hud_action_append(actions, "pause", &launch_pause, game);
    actions = hud_action_append(actions, "slot", &inventory_slot_action, game);
    actions = hud_action_append(actions, "stats", &launch_stats, game);
    actions = hud_action_append(actions, "skill", &launch_skill, game);
    if ((game->menus.inventory_menu = hud_init(game->win, actions,
    "assets/hud/inventory.txt")) == NULL)
        return -1;
    if (!hud_check_buttons(game->menus.inventory_menu, buttons) ||
        !hud_check_views(game->menus.inventory_menu, views))
        return -2;
    game->menus.inventory.inventory_wait = sfClock_create();
    if (init_inventory_struct(game) < 0 ||
        init_inventory_slots(game, "inventory_slots") < 0 ||
        init_inventory_slots(game, "inventory_bar") < 0)
        return -3;
    return 0;
}
