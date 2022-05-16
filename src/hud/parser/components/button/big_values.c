/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** action
*/

#include "hud.h"

hud_button_t *hud_parser_button_set_action(hud_t *hud, hud_button_t *button,
const char *name)
{
    for (list_t *action = hud->actions; action != NULL; action = action->next) {
        if (my_strcmp(((hud_action_t *)action->data)->name, name) == 0) {
            button->action = ((hud_action_t *)action->data);
            return button;
        }
    }
    my_printerr("\t -> action '%s' does not exist", name);
    return button;
}

static void hud_parser_button_get_text_2(hud_button_t *button, char **keys,
char *text)
{
    char *key = NULL;
    sfColor color = {255, 255, 255, 255};
    int size = 20;

    if ((key = hud_parser_get_key(keys, "fontColor=")) != NULL) {
        color = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "fontSize=")) != NULL) {
        size = hud_parser_int(key);
        free(key);
    }
    if (text != NULL) {
        sfText_setString(button->text, text);
        free(text);
    }
    sfText_setColor(button->text, color);
    sfText_setCharacterSize(button->text, size);
}

void hud_parser_button_get_text(hud_button_t *button, char **keys)
{
    char *key = NULL;
    char *text = NULL;

    if ((key = hud_parser_get_key(keys, "font=")) != NULL) {
        button->font = hud_font_set(key);
        free(key);
    }
    if (button->font == NULL)
        return;
    if ((button->text = sfText_create()) == NULL)
        return;
    sfText_setFont(button->text, button->font);
    if ((key = hud_parser_get_key(keys, "text=")) != NULL) {
        text = hud_parser_str(key);
        free(key);
    }
    hud_parser_button_get_text_2(button, keys, text);
}

void hud_parser_button_get_other(hud_t *hud, hud_button_t *button, char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "action=")) != NULL) {
        button->action = hud_action_get(hud, key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "texture=")) != NULL) {
        button->texture = hud_texture_set(key);
        free(key);
    }
}
