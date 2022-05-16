/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** create_bosses
*/

#include "draw.h"

sfIntRect create_rect_boss(int width, int height)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return rect;
}

void boss_texture(boss_t *boss, int nb_phases)
{
    boss->textures[nb_phases] = NULL;
    boss->direction = DOWN_STATIC;
    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite, boss->textures[0], sfTrue);
    sfSprite_setTextureRect(boss->sprite, boss->rect[0]);
}

boss_t *create_bosses(char **filepaths, int nb_phases,
sfVector2i *size, sfVector2f pos)
{
    boss_t *boss = malloc(sizeof(boss_t));

    boss->textures = malloc(sizeof(sfTexture *) * (nb_phases + 1));
    boss->rect = malloc(sizeof(sfIntRect) * nb_phases);
    for (int i = 0; i < nb_phases; i++) {
        boss->textures[i] = sfTexture_createFromFile(filepaths[i], NULL);
        boss->rect[i] = create_rect_boss(size[i].x, size[i].y);
    }
    boss_texture(boss, nb_phases);
    boss->pos = pos;
    boss->sprite = sfSprite_create();
    boss->clock = sfClock_create();
    boss->move_clock = sfClock_create();
    boss->phase = 0;
    boss->nb_phase = nb_phases;
    boss->hp = 100.0f;
    boss->is_trigger = 0;
    boss->speed = 1.0f;
    return boss;
}
