/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** boss_fight
*/

#include "event.h"
#include "draw.h"

void dead_old_man(game_t *game, boss_t *boss)
{
    if (boss->hp <= 0) {
        sfSprite_setColor(boss->sprite, sfColor_fromRGBA(255, 255, 255, 0));
        sfSprite_setColor(game->all_spt.knife->sprite,
        sfColor_fromRGBA(255, 255, 255, 0));
        sfSprite_setColor(game->all_spt.explosion->sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
        boss_explosion(game, game->all_spt.explosion, boss);
        if (game->npc_death.dead_old_man == 0)
            game->npc_death.dead_old_man = 1;
    }
}

void old_man_knife(game_t *game, boss_t *boss)
{
    if (boss->direction == LEFT_STATIC) {
        sfSprite_setRotation(game->all_spt.knife->sprite, 270);
        sfSprite_setPosition(game->all_spt.knife->sprite,
        (sfVector2f){boss->pos.x - 50, boss->pos.y + 5});
    }
    if (boss->direction == RIGHT_STATIC) {
        sfSprite_setRotation(game->all_spt.knife->sprite, 90);
        sfSprite_setPosition(game->all_spt.knife->sprite,
        (sfVector2f){boss->pos.x + 50, boss->pos.y - 5});
    }
    if (boss->direction == DOWN_STATIC) {
        sfSprite_setRotation(game->all_spt.knife->sprite, 180);
        sfSprite_setPosition(game->all_spt.knife->sprite,
        (sfVector2f){boss->pos.x + 5, boss->pos.y + 50});
    }
    if (boss->direction == UP_STATIC) {
        sfSprite_setRotation(game->all_spt.knife->sprite, 0);
        sfSprite_setPosition(game->all_spt.knife->sprite,
        (sfVector2f){boss->pos.x - 5, boss->pos.y - 50});
    }
}

void boss_deplacement(game_t *game)
{
    sfVector2f pos;
    for (list_t *tmp = game->boss; tmp != NULL; tmp = tmp->next) {
        if (((boss_t *)tmp->data)->hp <= 0
            || (((boss_t *)tmp->data)->is_trigger == 0))
            continue;
        pos = ((boss_t *)tmp->data)->pos;
        if (pos.y > game->all_spt.player->pos.y)
            pos.y -= 1;
        if (pos.y < game->all_spt.player->pos.y)
            pos.y += 1;
        if (pos.x > game->all_spt.player->pos.x)
            pos.x -= 1;
        if (pos.x < game->all_spt.player->pos.x)
            pos.x += 1;
        if (check_collision(game, pos.x, pos.y) == true)
            ((boss_t *)tmp->data)->pos = pos;
    }
}
