/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** hud
*/

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>
#include "list.h"
#include "my.h"
#include "printf.h"
#include "printerr.h"

#ifndef HUD_H
    #define HUD_H

    #define DEBUG_MODE 0
    #define HUD_SIZE_X 800
    #define HUD_SIZE_Y 600
    #define DPRINT(...) if (DEBUG_MODE == 1) my_printf(__VA_ARGS__)
    #define DPRINTR(...) if (DEBUG_MODE == 1) my_printerr(__VA_ARGS__)

typedef struct hud_button_s hud_button_t;

typedef struct hud_action_s {
    char *name;
    void (*function)(hud_button_t *self, void *param);
    void *param;
} hud_action_t;

typedef struct hud_button_s {
    char *name;
    int key;
    sfIntRect pos;
    bool hidden;
    bool border;
    sfFloatRect borderWidth;
    sfColor borderColor;
    sfColor color;
    hud_action_t *action;
    sfTexture *texture;
    sfColor actionBorderColor;
    sfColor actionColor;
    sfText *text;
    sfFont *font;
    bool toggleable;
    bool toggle;
    bool hover;
} hud_button_t;

typedef struct hud_view_s {
    char *name;
    sfIntRect pos;
    bool hidden;
    bool border;
    sfFloatRect borderWidth;
    sfColor borderColor;
    sfColor color;
    sfTexture *texture;
    list_t *views;
    list_t *buttons;
} hud_view_t;

typedef struct hud_s {
    list_t *views;
    list_t *buttons;
    list_t *all_views;
    list_t *all_buttons;
    sfRenderWindow *win;
    list_t *actions;
    sfClock *clock;
} hud_t;

void free_char_arr(char **arr);
char *file_to_str(char *filepath);
char *str_dup_from_to(char *base, char start, char end);

sfVertexArray *hud_create_rect(sfFloatRect pos, sfColor color,
sfVector2f view_pos, sfTexture *texture);

sfTexture *hud_texture_set(const char *path);
sfFont *hud_font_set(char *path);
void hud_button_set_pos(hud_button_t *button, int x, int y);
void hud_button_set_size(hud_button_t *button, int x, int y);
void hud_button_set_border_size(hud_button_t *button, sfFloatRect borderWidth);

list_t *hud_action_append(list_t *actions, char *name,
void (*function)(hud_button_t *self, void *param), void *param);
hud_action_t *hud_action_get(hud_t *hud, char *name);

void hud_parser_button_get_value(hud_button_t *button, char **keys);
void hud_parser_button_get_other(hud_t *hud, hud_button_t *button, char **keys);
void hud_parser_button_get_text(hud_button_t *button, char **keys);

void hud_parser_view_get_value(hud_view_t *view, char **keys);
void hud_parser_view_get_other(hud_t *hud __attribute__ ((unused)),
hud_view_t *view, char **keys);

int hud_parser_extractor(char *schemat, hud_t *hud);
char *hud_parser_skip_tag(char *schemat);
char **hud_parser_get_keys(char *keys);
char *hud_parser_get_key(char **keys_arr, char *key);

bool hud_parser_bool(char *bool_constr);
char *hud_parser_str(char *str_constr);
int hud_parser_int(char *int_constr);
sfIntRect hud_parser_int_rect(char *rect_constr);
sfFloatRect hud_parser_float_rect(char *rect_constr);
sfColor hud_parser_sfcolor(char *color_constr);

const char *hud_parser_button_parser(char *schemat, hud_t *hud,
list_t **container);
const char *hud_parser_view_parser(char *schemat, hud_t *hud,
list_t **container);

hud_t *hud_init_struct(sfRenderWindow *win, list_t *actions);
hud_t *hud_init(sfRenderWindow *win, list_t *actions, char *schemat_path);
hud_button_t *hud_button_init(void);
hud_view_t *hud_view_init(void);

bool hud_check_buttons(hud_t *hud, const char **buttons_name);
bool hud_check_views(hud_t *hud, const char **views_name);

void hud_render(hud_t *hud);
void hud_render_buttons(hud_t *hud, list_t *buttons, sfVector2f view_pos);
void hud_render_views(hud_t *hud, list_t *views, sfVector2f view_pos);
void hud_button_render(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos);
void hud_view_render(sfRenderWindow *win, hud_view_t *view,
sfVector2f view_pos);

void hud_draw_vertexrect(sfRenderWindow *win, sfVertexArray *rect);
void hud_draw_rect(sfRenderWindow *win, sfFloatRect pos, sfColor color,
sfVector2f view_pos);

int hud_event(hud_t *hud);
int hud_event_mouse(hud_t *hud);
int hud_event_keyboard(hud_t *hud);

hud_button_t *hud_button_get(hud_t *hud, const char *name);
hud_view_t *hud_view_get(hud_t *hud, const char *name);

void free_hud(hud_t *hud);

#endif
