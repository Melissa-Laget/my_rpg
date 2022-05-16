/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** game
*/

#include "draw.h"
#include "event.h"

void check_damage(game_t *game, list_t *boss)
{
    if (boss->prev == NULL)
        damage_player(game, ((boss_t *)boss->data));
    if (boss->next == NULL)
        damage_sword_player(game);
}

static void damage_boss_npc(game_t *game)
{
    for (list_t *tmp = game->boss; tmp != NULL &&
        ((boss_t *)tmp->data)->phase != ((boss_t *)tmp->data)->nb_phase;
        tmp = tmp->next) {
        if ((spell_damage(game->all_spt.fire, ((boss_t *)tmp->data)) == 0)
            && (spell_damage(game->all_spt.ice, ((boss_t *)tmp->data)) == 0)
            && (spell_damage(game->all_spt.poison, ((boss_t *)tmp->data)) == 0)
            && (damage_enemy(game, ((boss_t *)tmp->data)) == 0)) {
            sfSprite_setColor(((boss_t *)tmp->data)->sprite,
            sfColor_fromRGBA(255, 255, 255, 255));
        }
        check_damage(game, tmp);
    }
    for (list_t *tmp = game->npc; tmp != NULL; tmp = tmp->next) {
        if ((spell_damage_n(game->all_spt.fire, ((player_t *)tmp->data)) == 0)
            && (spell_damage_n(game->all_spt.ice, ((player_t *)tmp->data)) == 0
            ) && (spell_damage_n(game->all_spt.poison, ((player_t *)tmp->data))
            == 0) && (damage_npc(game, ((player_t *)tmp->data)) == 0))
                continue;
    }
}

void all_event(game_t *game)
{
    if (player_no_mouvement(game->all_spt.player) == 0)
        sfView_setCenter(game->view, ((sfVector2f){
        game->all_spt.player->pos.x + game->all_spt.player->rect.width / 2,
        game->all_spt.player->pos.y + game->all_spt.player->rect.height / 2
        }));
    if (game->all_spt.sword->attack != 1)
        player_mouvement(game);
    player_event(game);
    damage_boss_npc(game);
    check_death(game);
}
