/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** player
*/

#include "draw.h"
#include "event.h"
#include "actions.h"

int enemy_color(attack_t *spell)
{
    if (spell->status == 2) {
        if (sfClock_getElapsedTime(spell->clock).microseconds > 300000) {
            sfClock_restart(spell->clock);
            spell->status = 0;
        }
        spell->attack = 0;
        return 1;
    }
    return 0;
}

int spell_damage(attack_t *spell, boss_t *boss)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(spell->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(boss->sprite);

    if (enemy_color(spell) == 1)
        return 1;
    if (sfClock_getElapsedTime(spell->clock).microseconds < 500000) {
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue
            && spell->status == 0 && spell->attack == 1 && boss->hp > 0) {
            spell->status = 2;
            sfSprite_setColor(boss->sprite, sfColor_fromRGBA(255, 0, 0, 255));
            boss->hp -= 3.5;
            spell->attack = 0;
            sfClock_restart(spell->clock);
            return 1;
        }
        return 0;
    }
    spell->attack = 0;
    sfClock_restart(spell->clock);
    return 0;
}

int damage_enemy(game_t *game, boss_t *boss)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(game->all_spt.sword->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(boss->sprite);

    rect1 = sword_collision_direction(game, rect1);
    if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue
        && game->all_spt.sword->attack == 1 && boss->hp > 0) {
        sfSprite_setColor(boss->sprite, sfColor_fromRGBA(255, 0, 0, 255));
        boss->hp -= 0.25 * (game->skill_tree.strength + 1);
        return 1;
    }
    return 0;
}

static void dead_characters(game_t *game, list_t *tmp, int *dead)
{
    if (can_talk(game, ((player_t *)tmp->data)) == 1) {
        sfColor npc_color = sfSprite_getColor(((player_t *)tmp->data)->sprite);
        if (npc_color.a == 0 && dead[0] == 0) {
            dead[0] = 1;
            append_to_inventory(game, WOOD_ITEM);
        }
    }
}

int damage_npc(game_t *game, player_t *npc)
{
    list_t *tmp = game->npc;
    sfFloatRect rect1 = sfSprite_getGlobalBounds(game->all_spt.sword->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(npc->sprite);

    rect1 = sword_collision_direction(game, rect1);
    if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue
        && game->all_spt.sword->attack == 1) {
        sfSprite_setColor(npc->sprite, sfColor_fromRGBA(255, 255, 255, 0));
        npc->hp -= npc->hp;
        dead_characters(game, tmp, &game->npc_death.dead_orc);
        dead_characters(game, tmp->next, &game->npc_death.dead_lumberjack);
        dead_characters(game, tmp->next->next, &game->npc_death.dead_villager);
        dead_characters(game,
        tmp->next->next->next, &game->npc_death.dead_guard);
        return 1;
    }
    return 0;
}

int spell_damage_n(attack_t *spell, player_t *npc)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(spell->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(npc->sprite);

    if (sfClock_getElapsedTime(spell->clock).microseconds < 500000) {
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue
            && spell->status == 0 && spell->attack == 1) {
            spell->status = 2;
            sfSprite_setColor(npc->sprite, sfColor_fromRGBA(0, 0, 0, 0));
            npc->hp -= npc->hp;
            spell->attack = 0;
            sfClock_restart(spell->clock);
            return 1;
        }
        return 0;
    }
    spell->attack = 0;
    sfClock_restart(spell->clock);
    return 0;
}
