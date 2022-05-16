/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** draw
*/

#ifndef DRAW_H_
    #define DRAW_H_

    #include "rpg.h"

/* create sprites */
void create_all_sprite(game_t *game);

player_t *create_player(char *filepath, float pos_x, float pos_y);
sfIntRect create_rect_player(player_t *player);

attack_t *create_sword(char *filepath, int width, int height);
sfIntRect create_rect_sword(attack_t *sword, int width, int height);

boss_t *create_bosses(char **filepaths, int nb_phases,
sfVector2i *size, sfVector2f pos);
sfIntRect create_rect_boss(int rect_width, int rect_height);

attack_t *create_ice_poison(char *filepath);
attack_t *create_fire(char *filepath);
sfIntRect create_rect_spell(attack_t *spell, int width, int height);

int create_particles(game_t *game);
int create_particle(sfFloatRect pos_dir, sfTexture *texture,
list_t **particles);
void create_skill_tree(game_t *game);

/* lists */
list_t *boss_list(void);
list_t *villager_list(void);
void text_list(list_t *npc);

/* directions */
void spell_direction(attack_t *spell, int direction, sfVector2f pos);
void sword_direction(attack_t *sword, player_t *player);
sfFloatRect sword_collision_direction(game_t *game, sfFloatRect rect);

/* animations */
void player_animation(player_t *player);
void attack_animation(game_t *game);
void spell_animation(attack_t *spell, int frames, int size);
void sword_animation(attack_t *sword, player_t *player);

void boss_animation(boss_t *boss);
void boss_direction(player_t *player, boss_t *boss);
void boss_animation_throw(boss_t *boss);
void boss_animation_phase(boss_t *boss);
void boss_animation_dead(boss_t *boss);
void boss_explosion(game_t *game, player_t *explosion, boss_t *boss);
void change_phase(player_t *player, boss_t *boss, game_t *game);

void npc_animation(player_t *player, player_t *npc);

void particles_animation(list_t **particles);

/* draw */
void draw_all(game_t *game);
void draw_map(game_t *game);
int draw_boss(game_t *game);
int draw_npc(game_t *game);
void draw_particles(game_t *game);
void player_text(game_t *game, const char *str, sfVector2f pos, int text_size);
int update_inventory(game_t *game);

/* damage */
int damage_enemy(game_t *game, boss_t *boss);
int damage_player(game_t *game, boss_t *boss);
int damage_sword_player(game_t *game);
int spell_damage_n(attack_t *spell, player_t *npc);
int damage_npc(game_t *game, player_t *npc);
void check_death(game_t *game);
int spell_damage(attack_t *spell, boss_t *boss);

/* dialogs */
void show_text(game_t *game);
void talk_text(game_t *game);
void text_event(game_t *game);

/* huds */
int init_huds(game_t *game);
int init_main_menu(game_t *game);
int init_main_hud(game_t *game);
int init_inventory(game_t *game);
int init_pause_menu(game_t *game);
int init_stats_menu(game_t *game);
int init_skill_tree_menu(game_t *game);
int init_dead_menu(game_t *game);

void draw_main_menu(game_t *game);
void draw_main_hud(game_t *game);
void draw_inventory(game_t *game);
void draw_pause(game_t *game);
void draw_stats(game_t *game);
void draw_skill(game_t *game);
void draw_dead(game_t *game);

/* cutscene */
void cutscene(game_t *game);

/* destroy */
void destroy_particle(particle_t *particle);

#endif
