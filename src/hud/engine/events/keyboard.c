/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** clic
*/

#include "hud.h"

int hud_event_button_keyboard(hud_button_t *button)
{
    if (button->key == -1)
        return 0;
    if (sfKeyboard_isKeyPressed(button->key) == sfTrue) {
        if (button->toggleable == true)
            button->toggle = (!(button->toggle));
        if (button->action != NULL && button->action->function != NULL) {
            button->action->function(button, button->action->param);
        }
        return 1;
    }
    return 0;
}

int hud_event_keyboard(hud_t *hud)
{
    int used = 0;

    for (list_t *buttons = hud->all_buttons; buttons != NULL;
        buttons = buttons->next) {
        used |= hud_event_button_keyboard(buttons->data);
    }
    return used;
}
