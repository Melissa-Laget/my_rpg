/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** create_spell
*/

#include "draw.h"
#include "list.h"
#include <stdlib.h>

sfIntRect create_rect_spell(attack_t *spell, int width, int height)
{
    spell->rect.top = 0;
    spell->rect.left = 0;
    spell->rect.width = width;
    spell->rect.height = height;
    return spell->rect;
}

attack_t *create_ice_poison(char *filepath)
{
    attack_t *spell = malloc(sizeof(attack_t));

    spell->sprite = sfSprite_create();
    spell->texture = sfTexture_createFromFile(filepath, NULL);
    spell->rect = create_rect_spell(spell, 83, 54);
    sfSprite_setTexture(spell->sprite, spell->texture, sfTrue);
    sfSprite_setTextureRect(spell->sprite, spell->rect);
    sfSprite_setColor(spell->sprite, sfColor_fromRGBA(255, 255, 255, 0));
    sfSprite_setScale(spell->sprite, ((sfVector2f){0.7, 0.7}));
    spell->status = 0;
    spell->clock = sfClock_create();
    spell->anim_clock = sfClock_create();
    spell->attack = 0;
    return spell;
}

attack_t *create_fire(char *filepath)
{
    attack_t *spell = malloc(sizeof(attack_t));

    spell->sprite = sfSprite_create();
    spell->texture = sfTexture_createFromFile(filepath, NULL);
    spell->rect = create_rect_spell(spell, 83, 46);
    sfSprite_setTexture(spell->sprite, spell->texture, sfTrue);
    sfSprite_setTextureRect(spell->sprite, spell->rect);
    sfSprite_setColor(spell->sprite, sfColor_fromRGBA(255, 255, 255, 0));
    sfSprite_setScale(spell->sprite, ((sfVector2f){0.7, 0.7}));
    spell->status = 0;
    spell->clock = sfClock_create();
    spell->anim_clock = sfClock_create();
    spell->attack = 0;
    return spell;
}
