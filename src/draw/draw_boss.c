/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** draw_boss
*/

#include "draw.h"
#include "event.h"

void attack_phase(player_t *player, boss_t *boss)
{
    if (boss->hp > 0 && (boss->phase == 0)) {
        if (player->pos.x <= boss->pos.x && player->pos.x >= boss->pos.x - 100
            && player->pos.y - 50 <= boss->pos.y
            && player->pos.y + 50 >= boss->pos.y)
            boss->phase = 1;
        if (player->pos.x >= boss->pos.x && player->pos.x <= boss->pos.x + 100
            && player->pos.y - 50 <= boss->pos.y
            && player->pos.y + 50 >= boss->pos.y)
            boss->phase = 1;
        if (player->pos.y >= boss->pos.y && player->pos.y <= boss->pos.y + 100
            && player->pos.x - 50 <= boss->pos.x
            && player->pos.x + 50 >= boss->pos.x)
            boss->phase = 1;
        if (player->pos.y <= boss->pos.y && player->pos.y >= boss->pos.y - 100
            && player->pos.x - 50 <= boss->pos.x
            && player->pos.x + 50 >= boss->pos.x)
            boss->phase = 1;
    }
}

void change_phase(player_t *player, boss_t *boss, game_t *game)
{
    if ((boss->hp > 0 && boss->hp < 45) || (boss->hp > 50 && boss->hp <= 100))
        boss->phase = 0;
    if (boss->hp >= 45 && boss->hp <= 50) {
        boss->phase = 2;
        boss->speed = 1.1;
    }
    if (boss->hp <= 0) {
        boss->phase = 3;
        if (game->npc_death.dead_morshu == 0)
            game->npc_death.dead_morshu = 1;
    }
    attack_phase(player, boss);
}

int draw_boss(game_t *game)
{
    dead_old_man(game, game->boss->next->data);
    for (list_t *tmp = game->boss; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->win, ((boss_t *)tmp->data)->sprite,
        NULL);
        if (sfClock_getElapsedTime(
            ((boss_t *)tmp->data)->move_clock).microseconds < 30000)
            continue;
        sfClock_restart(((boss_t *)tmp->data)->move_clock);
        sfSprite_setPosition(((boss_t *)tmp->data)->sprite,
        ((boss_t *)tmp->data)->pos);
        if (tmp->next != NULL)
            change_phase(game->all_spt.player, ((boss_t *)tmp->data), game);
        boss_deplacement(game);
        if (tmp->next == NULL)
            old_man_knife(game, tmp->data);
        sfSprite_setPosition(((boss_t *)tmp->data)->sprite,
        ((boss_t *)tmp->data)->pos);
    }
    return 0;
}
