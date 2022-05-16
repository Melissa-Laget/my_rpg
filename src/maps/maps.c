/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-bsmysokoban-melissa.laget [WSL: Manjaro]
** File description:
** maps
*/

#include "event.h"
#include "my.h"

static int read_map_size(char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    int i = 0;
    char buff[1];

    if (filedesc < 0)
        return 0;
    for (; read(filedesc, buff, 1) > 0; i++);
    close(filedesc);
    return i - 1;
}

char *file_to_str(char *filepath)
{
    int size = read_map_size(filepath);
    char *buff = NULL;
    int filedesc = open(filepath, O_RDONLY);

    if (filedesc < 0)
        return NULL;
    buff = malloc(sizeof(char) * size + 1);
    if (read(filedesc, buff, size) < 1)
        return NULL;
    buff[size] = '\0';
    return buff;
}
