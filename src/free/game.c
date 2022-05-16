/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** game
*/

#include "draw.h"
#include "list.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void free_player(player_t *draw)
{
    if (!draw)
        return;
    if (draw->sprite)
        sfSprite_destroy(draw->sprite);
    if (draw->texture)
        sfTexture_destroy(draw->texture);
    if (draw->clock)
        sfClock_destroy(draw->clock);
    free(draw);
}

void free_npc(list_t *npc)
{
    list_t *tmp = npc;

    while (tmp != NULL) {
        free_player(((player_t *)tmp->data));
        tmp = tmp->next;
    }
    list_free(npc, false);
}

void free_attack(attack_t *attack)
{
    sfSprite_destroy(attack->sprite);
    sfTexture_destroy(attack->texture);
    if (attack->clock)
        sfClock_destroy(attack->clock);
    if (attack->anim_clock)
        sfClock_destroy(attack->anim_clock);
    free(attack);
}

void free_all_sprites(game_t *game)
{
    sfSprite_destroy(game->all_spt.text);
    sfTexture_destroy(game->all_spt.text_texture);
    sfSprite_destroy(game->all_spt.textbox);
    sfTexture_destroy(game->all_spt.textbox_texture);
    free_attack(game->all_spt.sword);
    free_attack(game->all_spt.knife);
    free_attack(game->all_spt.fire);
    free_attack(game->all_spt.ice);
    free_attack(game->all_spt.poison);
    free_player(game->all_spt.explosion);
    sfClock_destroy(game->all_spt.cutscene.clock);
    sfSprite_destroy(game->all_spt.cutscene.sprite);
    sfTexture_destroy(game->all_spt.cutscene.texture);
}

void free_huds(game_t *game)
{
    free_hud(game->menus.main_menu);
    free_hud(game->menus.hud);
    free_hud(game->menus.inventory_menu);
    free_hud(game->menus.pause_menu);
    free_hud(game->menus.stats_menu);
}

void free_all(player_t *player, game_t *game)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    free(player);
    free_npc(game->npc);
    sfRenderWindow_destroy(game->win);
    sfMusic_destroy(game->sound.morshu_music);
    sfMusic_destroy(game->sound.died_music);
    sfMusic_destroy(game->sound.morshu_fight);
    sfMusic_destroy(game->sound.village_music);
    sfMusic_destroy(game->sound.old_man_fight);
    sfFont_destroy(game->font);
    sfText_destroy(game->talk_text);
    sfView_destroy(game->view);
    sfView_destroy(game->win_view);
    sfClock_destroy(game->rain_particles_clock);
    sfClock_destroy(game->walk_particles_clock);
    free_all_sprites(game);
    free(game);
}
