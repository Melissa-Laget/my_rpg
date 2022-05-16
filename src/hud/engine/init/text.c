/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** text
*/

#include "hud.h"
#include <fcntl.h>

sfFont *hud_font_set(char *path)
{
    int fd = open(path, O_RDONLY);
    sfFont *font;

    if (fd < 0) {
        my_printerr("\t\t>>> font not found: %s\n", path);
        return NULL;
    }
    close(fd);
    font = sfFont_createFromFile(path);
    if (font == NULL)
        my_printerr("\t\t>>> fail to load font: %s\n", path);
    return font;
}
