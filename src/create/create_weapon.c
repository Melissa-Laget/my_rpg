/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** create_weapon
*/

#include "draw.h"

sfIntRect create_rect_sword(attack_t *sword, int width, int height)
{
    sword->rect.top = 0;
    sword->rect.left = 0;
    sword->rect.width = width;
    sword->rect.height = height;
    return sword->rect;
}

attack_t *create_sword(char *filepath, int width, int height)
{
    attack_t *sword = malloc(sizeof(attack_t));

    sword->attack_direction = DOWN_ATK;
    sword->sprite = sfSprite_create();
    sword->texture = sfTexture_createFromFile(filepath, NULL);
    sword->rect = create_rect_sword(sword, width, height);
    sfSprite_setTexture(sword->sprite, sword->texture, sfTrue);
    sfSprite_setTextureRect(sword->sprite, sword->rect);
    sfSprite_setColor(sword->sprite, sfColor_fromRGBA(255, 255, 255, 0));
    sword->clock = sfClock_create();
    sword->anim_clock = NULL;
    sword->attack = 0;
    return (sword);
}
