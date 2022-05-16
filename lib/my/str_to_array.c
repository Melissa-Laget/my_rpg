/*
** EPITECH PROJECT, 2022
** str_to_array
** File description:
** str_to_array
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

char **get_separators(char *dict);
int is_in_array(char **str, char **array, bool move_ptr);
char **get_delimiters(char *dict);

int count_before_arr(char *str, char **arr, char **delim_arr, bool is_delim)
{
    int i = 0;
    bool delim = is_delim;

    for (; *str != '\0'; str++) {
        if (delim_arr != NULL && is_in_array(&str, delim_arr, true) == 1) {
            delim = (delim == false) ? true : false;
        }
        if (delim == true) {
            i++;
            continue;
        }
        if (is_in_array(&str, arr, false) == 1)
            break;
        i++;
    }
    if (is_delim)
        i--;
    return i;
}

int count_world(char *str, char **sep_arr, char **delim_arr)
{
    int count = 1;

    if (str == NULL || sep_arr == NULL)
        return -84;
    for (; *str != '\0' && is_in_array(&str, sep_arr, true) == 1;
        str += (*str != '\0'));
    for (; *str != '\0'; str += (*str != '\0'), count -= (*str == '\0')) {
        if (is_in_array(&str, delim_arr, true) == 1) {
            str = &str[count_before_arr(str, delim_arr, NULL, true)];
            is_in_array(&str, delim_arr, false);
            continue;
        }
        if (is_in_array(&str, sep_arr, false) == 1)
            count++;
        for (; *str != '\0' && is_in_array(&str, sep_arr, true) == 1;
            str += (*str != '\0'));
        if (is_in_array(&str, delim_arr, false) == 1)
            str--;
    }
    return count;
}

char **str_to_array(char *str, char *separators)
{
    char **arr = NULL;
    int item_count = 0;
    int count = 0;

    if (str == NULL || separators == NULL)
        return NULL;
    for (; *str != '\0' && is_in_str(separators, *str); str++);
    item_count = count_with_separators(str, separators);
    arr = malloc(sizeof(char*) * (item_count + 1));
    for (int i = 0; i < item_count; i++) {
        arr[i] = NULL;
        for (; *str != '\0' && is_in_str(separators, *str); str++);
        if ((count = count_char_before_separator(str, separators)) == -84)
            return NULL;
        if ((arr[i] = my_strndup(str, count)) == NULL)
            return NULL;
        (i != item_count) ? (str = &str[count + 1]) : NULL;
    }
    arr[item_count] = NULL;
    return arr;
}

char **str_to_array_s_func(char *str, char **sep_arr, char **delim_arr,
int nb_word)
{
    int count = 0;
    bool delim = false;
    char **arr = NULL;

    if (nb_word == -84 || (arr = malloc(sizeof(char *) *
        (nb_word + 1))) == NULL)
        return NULL;
    for (int i = 0; *str != '\0' && i < nb_word; i++) {
        delim = false;
        for (; *str != '\0' && is_in_array(&str, sep_arr, true) == 1; str++);
        for (; *str != '\0' && is_in_array(&str, delim_arr, true) == 1; str++)
            delim = true;
        count = count_before_arr(str, sep_arr, delim_arr, delim);
        if ((arr[i] = my_strndup(str, count)) == NULL)
            return NULL;
        (i != nb_word) ? (str = &str[count]) : NULL;
    }
    return arr;
}

char **str_to_array_s(char *str, char *separators)
{
    char **sep_arr = NULL;
    char **delim_arr = NULL;
    char **arr = NULL;
    int nb_word = 0;

    if (separators == NULL || str == NULL)
        return NULL;
    sep_arr = get_separators(separators);
    delim_arr = get_delimiters(separators);
    if (sep_arr == NULL)
        return NULL;
    if ((nb_word = count_world(str, sep_arr, delim_arr)) == -84)
        return NULL;
    arr = str_to_array_s_func(str, sep_arr, delim_arr, nb_word);
    if (arr == NULL)
        return NULL;
    arr[nb_word] = NULL;
    free_arr((void **)sep_arr);
    free_arr((void **)delim_arr);
    return arr;
}
