/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** spell_anim
*/

#include "draw.h"

void spell_animation(attack_t *spell, int frames, int size)
{
    sfSprite_setColor(spell->sprite, sfColor_fromRGBA(255, 255, 255, 255));
    if (sfClock_getElapsedTime(spell->anim_clock).microseconds > 750) {
        if (spell->rect.left >= 0 && spell->rect.left < frames * size) {
            spell->rect.left += size;
        } else {
            spell->rect.left = 0;
        }
        sfSprite_setTextureRect(spell->sprite, spell->rect);
        sfClock_restart(spell->anim_clock);
    }
}
