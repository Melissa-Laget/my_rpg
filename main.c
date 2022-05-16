/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include "draw.h"
#include "my.h"
#include "rpg.h"
#include <stddef.h>

int main(int argc, char **argv __attribute__((unused)), char **env)
{
    if (argc != 1 || !env || !*env || is_env_correct(env) == 0)
        return 84;
    return rpg();
}
