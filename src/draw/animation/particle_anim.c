/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** particle_anim
*/

#include "draw.h"

void particle_animation(particle_t *particle)
{
    if (particle->direction.x == 0 && particle->direction.y == 0) {
        particle->pos.x += ((rand() % 6) - 2.5);
        particle->pos.y += ((rand() % 6) - 2.5);
    }
    particle->pos.x += particle->direction.x;
    particle->pos.y += particle->direction.y;
    particle->lifetime -= 1;
    sfSprite_setColor(particle->sprite, ((sfColor){255, 255, 255,
    ((particle->lifetime * 5 > 255 ||
    particle->lifetime * 5 < 0) ? 255 : particle->lifetime * 5)}));
    sfSprite_setPosition(particle->sprite, particle->pos);
}

void particles_animation(list_t **particles)
{
    for (list_t *tmp = *particles; tmp != NULL; tmp = tmp->next) {
        if (sfClock_getElapsedTime(
            ((particle_t *)tmp->data)->clock).microseconds < 15000)
            continue;
        particle_animation(tmp->data);
        sfClock_restart(((particle_t *)tmp->data)->clock);
        if (((particle_t *)tmp->data)->lifetime <= 0) {
            destroy_particle(tmp->data);
            tmp = list_del_current(tmp, true);
            *particles = list_get_start(tmp);
            break;
        }
    }
}

void draw_particles(game_t *game)
{
    for (list_t *tmp = game->walk_particles; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(game->win,
        ((particle_t *)tmp->data)->sprite, NULL);
    for (list_t *tmp = game->rain_particles; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(game->win,
        ((particle_t *)tmp->data)->sprite, NULL);

}
