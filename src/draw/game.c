/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** game
*/

#include "rpg.h"
#include "event.h"
#include "draw.h"
#include "list.h"
#include <stdlib.h>

static const void (*boss_animations_funcs[])(boss_t *boss) = {
    &boss_animation,
    &boss_animation_throw,
    &boss_animation_phase,
    &boss_animation_dead,
};

void draw_spell(game_t *game)
{
    if (game->all_spt.fire->attack == 0) {
        sfSprite_setColor(game->all_spt.fire->sprite,
        sfColor_fromRGBA(255, 255, 255, 0));
        spell_direction(game->all_spt.fire,
        game->all_spt.player->direction, game->all_spt.player->pos);
    }
    if (game->all_spt.ice->attack == 0) {
        sfSprite_setColor(game->all_spt.ice->sprite,
        sfColor_fromRGBA(255, 255, 255, 0));
        spell_direction(game->all_spt.ice,
        game->all_spt.player->direction, game->all_spt.player->pos);
    }
    if (game->all_spt.poison->attack == 0) {
        sfSprite_setColor(game->all_spt.poison->sprite,
        sfColor_fromRGBA(255, 255, 255, 0));
        spell_direction(game->all_spt.poison,
        game->all_spt.player->direction, game->all_spt.player->pos);
    }
}

void draw_all_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->win, game->all_spt.knife->sprite, NULL);
    draw_boss(game);
    draw_spell(game);
    sfRenderWindow_drawSprite(game->win, game->all_spt.sword->sprite, NULL);
    sfRenderWindow_drawSprite(game->win, game->all_spt.player->sprite, NULL);
    draw_npc(game);
    sfRenderWindow_drawSprite(game->win, game->all_spt.fire->sprite, NULL);
    sfRenderWindow_drawSprite(game->win, game->all_spt.ice->sprite, NULL);
    sfRenderWindow_drawSprite(game->win, game->all_spt.poison->sprite, NULL);
}

void boss_animations(game_t *game)
{
    for (list_t *tmp = game->boss; tmp != NULL; tmp = tmp->next) {
        boss_direction(game->all_spt.player, ((boss_t *)tmp->data));
        boss_animations_funcs[((boss_t *)tmp->data)->phase](tmp->data);
    }
}

void generate_particles(game_t *game)
{
    if (sfClock_getElapsedTime(game->walk_particles_clock).microseconds >
        150000 && list_get_size(game->walk_particles) < 25) {
        create_particle(((sfFloatRect){
        game->all_spt.player->pos.x, game->all_spt.player->pos.y,
        0, 0}),
        game->particles_textures->data, &game->walk_particles);
        sfClock_restart(game->walk_particles_clock);
    }
    if (game->npc_death.dead_orc == 0)
        return;
    if (sfClock_getElapsedTime(game->rain_particles_clock).microseconds >
        150 && list_get_size(game->rain_particles) < 200000) {
        create_particle(((sfFloatRect){
        (rand() % game->mode.width), (rand() % game->mode.height),
        0.5, 5}),
        game->particles_textures->next->data, &game->rain_particles);
        sfClock_restart(game->rain_particles_clock);
    }
}

void draw(game_t *game)
{
    boss_animations(game);
    draw_all_sprite(game);
    player_animation(game->all_spt.player);
    generate_particles(game);
    particles_animation(&game->walk_particles);
    particles_animation(&game->rain_particles);
    if (game->all_spt.player->direction > UP_WALK)
        game->all_spt.player->direction -= 8;
}

void draw_all(game_t *game)
{
    sfSprite_setPosition(game->all_spt.player->sprite, (sfVector2f)
        {game->all_spt.player->pos.x, game->all_spt.player->pos.y});
    sword_direction(game->all_spt.sword, game->all_spt.player);
    attack_animation(game);
    move_spell(game);
    draw_map(game);
    draw_particles(game);
    draw(game);
    draw_map_depth(game);
    draw_main_hud(game);
    draw_inventory(game);
    text_event(game);
}
