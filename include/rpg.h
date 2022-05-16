/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/System/Vector2.h>
    #include "list.h"
    #include "hud.h"

    #define INVENTORY_ROW 4
    #define INVENTORY_COL 6

typedef struct all_sprite_s all_sprite_t;

typedef enum direction {
    DOWN_STATIC,
    LEFT_STATIC,
    RIGHT_STATIC,
    UP_STATIC,
    DOWN_WALK,
    LEFT_WALK,
    RIGHT_WALK,
    UP_WALK,
    DOWN_ATTACK,
    LEFT_ATTACK,
    RIGHT_ATTACK,
    UP_ATTACK,
} direction_t;

typedef enum attack_direction {
    DOWN_ATK,
    UP_ATK,
    RIGHT_ATK,
    LEFT_ATK,
} attack_direction_t;

typedef enum menu {
    EXIT_ERROR = -1,
    EXIT_GAME,
    MAIN_MENU,
    GAME_LOOP,
    PAUSE_MENU,
    STATS_MENU,
    SKILL_TREE,
    DEAD_MENU
} menu_t;

typedef enum items {
    NO_ITEM = -1,
    WOOD_ITEM
} items_t;

typedef struct background {
    sfTexture *texture;
    sfImage *colors;
    sfTexture *depth;
    sfVector2u depth_size;
    sfImage *collision_image;
    sfVector2u background_size;
    sfColor color;
} background_t;

typedef struct inventory_s {
    sfTexture **texture;
    int **items;
    hud_button_t ***slots;
    sfClock *inventory_wait;
} inventory_t;

typedef struct skill_tree_s {
    int strength;
    int defense;
    int unlock_magic;
    int fire_ball;
    int ice_ball;
    int poison_ball;
} skill_tree_t;

typedef struct game_menus_s {
    hud_t *main_menu;
    hud_t *hud;
    hud_t *pause_menu;
    hud_t *inventory_menu;
    hud_t *stats_menu;
    hud_t *skill_tree_menu;
    hud_t *dead;
    inventory_t inventory;
} game_menus_t;

typedef struct sound {
    bool muted;
    int dead;
    sfMusic *morshu_music;
    sfMusic *died_music;
    sfMusic *village_music;
    sfMusic *morshu_fight;
    sfMusic *old_man_fight;
    bool died_b;
    bool village_b;
    bool morshu_f_b;
    bool old_man_f_b;
} sound_t;

typedef struct npc {
    int talked_orc;
    int dead_orc;
    int dead_guard;
    int dead_lumberjack;
    int dead_morshu;
    int dead_old_man;
    int dead_villager;
    int log;
} npc_t;

typedef struct text_s {
    char **dialog;
    int nb_dialogs;
    bool skippable;
    int *text_size;
    sfVector2f *pos;
    int status;
    sfClock *clock;
} text_t;

typedef struct stat_text_s {
    sfText *text_fire;
    sfText *text_ice;
    sfText *text_poison;
    sfText *text_strenght;
    sfText *text_defense;
    sfText *text_magic;
    sfText *text_health;
} stat_text_t;

typedef struct particle_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f direction;
    int lifetime;
    sfClock *clock;
} particle_t;

typedef struct attack_s {
    attack_direction_t attack_direction;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfClock *anim_clock;
    sfVector2f pos;
    int attack;
    int status;
} attack_t;

typedef struct player_s {
    direction_t direction;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    float hp;
    text_t *text;
} player_t;

typedef struct boss_s {
    direction_t direction;
    sfSprite *sprite;
    sfTexture **textures;
    sfIntRect *rect;
    sfClock *clock;
    sfClock *move_clock;
    sfVector2f pos;
    int boss_status;
    int phase;
    int nb_phase;
    float hp;
    int is_trigger;
    float speed;
} boss_t;

typedef struct cutscene {
    int status_cutscene;
    sfClock *clock;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
} cutscene_t;

typedef struct all_sprite_s {
    player_t *player;
    sfSprite *text;
    sfTexture *text_texture;
    sfSprite *textbox;
    sfTexture *textbox_texture;
    attack_t *sword;
    attack_t *knife;
    attack_t *fire;
    attack_t *ice;
    attack_t *poison;
    player_t *explosion;
    cutscene_t cutscene;
} all_sprite_t;

typedef struct game_s {
    sfVideoMode mode;
    sfRenderWindow *win;
    char *save_path;
    sfFont *font;
    sfText *talk_text;
    all_sprite_t all_spt;
    sfClock *draw_clock;
    sfClock *event_clock;
    sfClock *text_clock;
    sfClock *damage_clock;
    int can_talk;
    int text_size;
    text_t *text;
    int status;
    game_menus_t menus;
    list_t *boss;
    list_t *npc;
    sfView *view;
    sfView *win_view;
    npc_t npc_death;
    skill_tree_t skill_tree;
    sound_t sound;
    background_t background;
    list_t *walk_particles;
    list_t *rain_particles;
    list_t *particles_textures;
    sfClock *walk_particles_clock;
    sfClock *rain_particles_clock;
    stat_text_t stat_text;
} game_t;

game_t *init_game(void);
int rpg(void);
int init_map(game_t *game);
int init_textures(game_t *game);
int is_env_correct(char **env);
void background_sprite(background_t *background, background_t *bg);
void draw_map_depth(game_t *game);
void init_hud_value(void);
char *nbr_to_str(int nbr);

/* music */
void create_game_music(game_t *game);
void launch_music(sfMusic *music, bool muted);

#endif
