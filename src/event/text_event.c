/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** text_event
*/

#include "draw.h"
#include "my.h"
#include <stdio.h>
#include "rpg.h"

void which_text(game_t *game, text_t *text);

static void text_start_display(game_t *game, player_t *npc)
{
    if ((hud_view_get(game->menus.inventory_menu, "inventory")->hidden) == 0)
        hud_view_get(game->menus.inventory_menu, "inventory_bar")->hidden = 0;
    else
        hud_view_get(game->menus.inventory_menu, "inventory_bar")->hidden = 1;
    which_text(game, npc->text);
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->can_talk == 1 &&
        npc->text->nb_dialogs - 1 > npc->text->status &&
        sfClock_getElapsedTime(npc->text->clock).microseconds > 1000000) {
        npc->text->status++;
        game->text_size = 0;
        sfClock_restart(npc->text->clock);
    }
}

int can_talk(game_t *game, player_t *npc)
{
    if (game->all_spt.player->pos.x > npc->pos.x - 45
        && game->all_spt.player->pos.x < npc->pos.x + 45
        && game->all_spt.player->pos.y > npc->pos.y - 45
        && game->all_spt.player->pos.y < npc->pos.y + 45)
        return 1;
    return 0;
}

static int check_talking(game_t *game, bool talk)
{
    if (talk == false) {
        game->text_size = 0;
        game->can_talk = 0;
        for (list_t *tmp = game->npc; tmp != NULL; tmp = tmp->next)
            ((player_t *)tmp->data)->text->status = 0;
        hud_view_get(game->menus.inventory_menu, "inventory_bar"
        )->hidden = false;
        return 1;
    }
    return 0;
}

static void check_can_talk(game_t *game, bool *talk)
{
    game->npc_death.talked_orc = 1;
    *talk = true;
}

void text_event(game_t *game)
{
    list_t *tmp = game->npc;
    bool talk = false;

    for (; tmp != NULL && ((player_t *)tmp->data)->hp; tmp = tmp->next) {
        if (game->npc_death.talked_orc == 0 && tmp->prev == NULL) {
            (can_talk(game, (player_t *)tmp->data)) ?
            check_can_talk(game, &talk) : NULL;
            return;
        }
        if (can_talk(game, ((player_t *)tmp->data))) {
            talk = true;
            break;
        }
    }
    if (check_talking(game, talk) == 1)
        return;
    text_start_display(game, tmp->data);
}
