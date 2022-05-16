/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** event
*/

#include "hud.h"

int hud_event(hud_t *hud)
{
    int res = 0;

    if (sfClock_getElapsedTime(hud->clock).microseconds < 150000)
        return 0;
    sfClock_restart(hud->clock);
    res |= hud_event_mouse(hud);
    res |= hud_event_keyboard(hud);
    return res;
}
