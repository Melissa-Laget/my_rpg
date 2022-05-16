/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** boss_anim
*/

#include "draw.h"

void boss_animation(boss_t *boss)
{
    if (sfClock_getElapsedTime(boss->clock).microseconds > 150000) {
        boss->rect[boss->phase].top = (boss->rect[boss->phase].height *
        boss->direction);
        if (boss->rect[boss->phase].left >= 0 &&
            boss->rect[boss->phase].left < boss->rect[boss->phase].width * 3) {
            boss->rect[boss->phase].left += boss->rect[boss->phase].width;
        } else {
            boss->rect[boss->phase].left = 0;
        }
        sfSprite_setTexture(boss->sprite, boss->textures[boss->phase], sfTrue);
        sfSprite_setTextureRect(boss->sprite, boss->rect[boss->phase]);
        sfSprite_setOrigin(boss->sprite, ((sfVector2f){
        boss->rect[boss->phase].width / 2, boss->rect[boss->phase].height / 2
        }));
        sfClock_restart(boss->clock);
    }
}

void boss_animation_throw(boss_t *boss)
{
    if (sfClock_getElapsedTime(boss->clock).microseconds > 150000) {
        boss->rect[boss->phase].top = 82 * boss->direction;
        if (boss->rect[boss->phase].left >= 0 &&
            boss->rect[boss->phase].left < 72) {
            boss->rect[boss->phase].left += 72;
        } else {
            boss->rect[boss->phase].left = 0;
        }
        sfSprite_setTexture(boss->sprite, boss->textures[boss->phase], sfTrue);
        sfSprite_setTextureRect(boss->sprite, boss->rect[boss->phase]);
        sfSprite_setOrigin(boss->sprite, ((sfVector2f){
        boss->rect[boss->phase].width / 2, boss->rect[boss->phase].height / 2
        }));
        sfClock_restart(boss->clock);
    }
}

void boss_animation_phase(boss_t *boss)
{
    if (sfClock_getElapsedTime(boss->clock).microseconds > 150000) {
        if (boss->rect[boss->phase].left >= 0 &&
            boss->rect[boss->phase].left < 58 * 3) {
            boss->rect[boss->phase].left += 58;
        } else {
            boss->rect[boss->phase].left = 0;
        }
        sfSprite_setTexture(boss->sprite, boss->textures[boss->phase], sfTrue);
        sfSprite_setTextureRect(boss->sprite, boss->rect[boss->phase]);
        sfSprite_setOrigin(boss->sprite, ((sfVector2f){
        boss->rect[boss->phase].width / 2, boss->rect[boss->phase].height / 2
        }));
        sfClock_restart(boss->clock);
    }
}

void boss_animation_dead(boss_t *boss)
{
    if (sfClock_getElapsedTime(boss->clock).microseconds > 150000) {
        if (boss->rect[boss->phase].left >= 0 &&
            boss->rect[boss->phase].left < 78 * 5) {
            boss->rect[boss->phase].left += 78;
        }
        sfSprite_setTexture(boss->sprite, boss->textures[boss->phase], sfTrue);
        sfSprite_setTextureRect(boss->sprite, boss->rect[boss->phase]);
        sfSprite_setOrigin(boss->sprite, ((sfVector2f){
        boss->rect[boss->phase].width / 2, boss->rect[boss->phase].height / 2
        }));
        sfClock_restart(boss->clock);
    }
}

void boss_explosion(game_t *game, player_t *explosion, boss_t *boss)
{
    if (sfClock_getElapsedTime(explosion->clock).microseconds > 100000) {
        if (explosion->rect.left >= 0 &&
            explosion->rect.left < 47 * 20) {
            explosion->rect.left += 47;
        }
        sfSprite_setTextureRect(explosion->sprite, explosion->rect);
        sfSprite_setOrigin(explosion->sprite, ((sfVector2f){
        explosion->rect.width / 2, explosion->rect.height / 2
        }));
        sfSprite_setPosition(explosion->sprite, boss->pos);
        sfClock_restart(explosion->clock);
    }
    sfRenderWindow_drawSprite(game->win, explosion->sprite, NULL);
}
