/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** my_tabl_len
*/

#include <unistd.h>
#include <stdlib.h>

int my_tabl_len(void **tabl)
{
    int i = 0;

    if (tabl == NULL)
        return -1;
    if (tabl[0] == NULL)
        return 0;
    for (i = 0; tabl[i] != NULL; i++);
    return i;
}

void free_arr(void **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}

void **del_in_arr(void **arr, int i)
{
    int size = my_tabl_len(arr);

    if (size < i)
        return arr;
    free(arr[i]);
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    arr[size - 1] = NULL;
    return arr;
}
