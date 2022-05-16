/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** clic
*/

#include "hud.h"

int hud_event_button_click(hud_button_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (button->toggleable == true)
            button->toggle = (!(button->toggle));
        if (button->action != NULL && button->action->function != NULL) {
            button->action->function(button, button->action->param);
        }
        return 3;
    }
    return 1;
}

int hud_event_button_hover(hud_button_t *button, sfVector2i offset,
sfVector2i mouse_pos, int used)
{
    if (button->hidden == false && used == 0 &&
            sfIntRect_contains(&((sfIntRect){
            .left = button->pos.left + offset.x,
            .top = button->pos.top + offset.y,
            .width = button->pos.width, .height = button->pos.height}),
            mouse_pos.x, mouse_pos.y) == sfTrue && used == 0) {
            button->hover = true;
            used |= hud_event_button_click(button);
        } else
            button->hover = false;
    return used;
}

int hud_event_analyze_buttons_mouse_input(list_t *buttons, sfVector2i mouse_pos,
sfVector2i offset, int used)
{
    if (buttons == NULL)
        return used;
    for (list_t *button = buttons; button != NULL && used == 0;
        button = button->next) {
        hud_event_button_hover(button->data, offset, mouse_pos, used);
    }
    return used;
}

int hud_event_analyze_views_mouse_input(list_t *views, sfVector2i mouse_pos,
sfVector2i offset, int used)
{
    sfVector2i view_pos;

    if (views == NULL)
        return used;
    for (list_t *view = views; view != NULL && used == 0;
        view = view->next) {
        if (((hud_view_t *)view->data)->hidden == true)
            continue;
        view_pos.x = ((hud_view_t *)view->data)->pos.left + offset.x;
        view_pos.y = ((hud_view_t *)view->data)->pos.top + offset.y;
        used |= hud_event_analyze_views_mouse_input(
        ((hud_view_t *)view->data)->views, mouse_pos, view_pos, used);
        used |= hud_event_analyze_buttons_mouse_input(
        ((hud_view_t *)view->data)->buttons, mouse_pos, view_pos, used);
    }
    return used;
}

int hud_event_mouse(hud_t *hud)
{
    int used = 0;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(hud->win);
    sfVector2u pos = sfRenderWindow_getSize(hud->win);

    mouse_pos.x = (mouse_pos.x * HUD_SIZE_X) / pos.x;
    mouse_pos.y = (mouse_pos.y * HUD_SIZE_Y) / pos.y;
    used |= hud_event_analyze_views_mouse_input(hud->views, mouse_pos,
    ((sfVector2i){.x = 0, .y = 0}), used);
    used |= hud_event_analyze_buttons_mouse_input(hud->buttons, mouse_pos,
    ((sfVector2i){.x = 0, .y = 0}), used);
    return used;
}
