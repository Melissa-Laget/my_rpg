/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** create_particle
*/

#include "draw.h"

int create_particles(game_t *game)
{
    sfTexture *texture = NULL;

    game->walk_particles = NULL;
    game->rain_particles = NULL;
    game->particles_textures = NULL;
    if (!(texture = sfTexture_createFromFile(
        "assets/particles/walk_particles.png",
        NULL)))
        return -1;
    game->particles_textures = list_append(game->particles_textures, texture);
    if (!(texture = sfTexture_createFromFile(
        "assets/particles/rain_particles.png",
        NULL)))
        return -2;
    game->particles_textures = list_append(game->particles_textures, texture);
    game->walk_particles_clock = sfClock_create();
    game->rain_particles_clock = sfClock_create();
    return 0;
}

int create_particle(sfFloatRect pos_dir, sfTexture *texture,
list_t **particles)
{
    particle_t *particle = malloc(sizeof(particle_t));
    int scale = (rand() % 10) + 10;

    particle->sprite = sfSprite_create();
    if (!particle || !texture || !particle->sprite)
        return -1;
    particle->texture = texture;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f){pos_dir.left, pos_dir.top});
    particle->direction = ((sfVector2f){pos_dir.width, pos_dir.height});
    particle->lifetime = 50;
    particle->clock = sfClock_create();
    sfSprite_setScale(particle->sprite,
    ((sfVector2f){scale / 10.f, scale / 10.f}));
    sfSprite_setPosition(particle->sprite, particle->pos);
    *particles = list_append(*particles, particle);
    return 0;
}

void destroy_particle(particle_t *particle)
{
    sfClock_destroy(particle->clock);
    sfSprite_destroy(particle->sprite);
}
