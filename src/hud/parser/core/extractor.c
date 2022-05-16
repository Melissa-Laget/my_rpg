/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** extractor
*/

#include "hud.h"

const char *hud_parser_extractor_view(char *schemat, hud_t *hud,
list_t **container);

static const int nb_balises = 2;
static const char *balises[] = {"<button", "<view"};
static const char *(*balises_func[])(char *, hud_t *, list_t **) = {
    &hud_parser_button_parser,
    &hud_parser_extractor_view
};

char *hud_parser_extractor_ignore(char *schemat)
{
    int i = 0;

    for (i = 0; schemat[i] == ' ' || schemat[i] == '\n' || schemat[i] == '\t';
        i++);
    schemat = &schemat[i];
    return schemat;
}

int hud_parser_get_balise(char *schemat)
{
    int balise_length = 0;

    for (int i = 0; i < nb_balises; i++) {
        balise_length = my_strlen(balises[i]);
        if (str_start_with(schemat, balises[i], my_strlen(schemat),
            balise_length) == 1) {
            DPRINT("\nfound balises: %s\n", &balises[i][1]);
            return i;
        }
    }
    DPRINTR("unknow balise: %15s\n", schemat);
    return -1;
}

char *hud_parser_extractor_view_extract(char *schemat, hud_t *hud,
list_t **list_type[2])
{
    int type = 0;

    while (schemat != NULL && schemat[0] != '\0') {
        schemat = hud_parser_extractor_ignore(schemat);
        if (schemat[0] == '\0' || (schemat[1] == '\0'))
            break;
        if (my_strncmp(schemat, "/>", 2) == 0) {
            DPRINT(">>>VIEW SUCCESSFULLY PARSED\n");
            return &schemat[2];
        }
        type = hud_parser_get_balise(schemat);
        if (type == -1) {
            schemat = hud_parser_skip_tag(schemat);
            continue;
        }
        schemat = &schemat[my_strlen(balises[type])];
        schemat = balises_func[type](schemat, hud, list_type[type]);
    }
    DPRINTR(">>>VIEW PARSING FAILED\n");
    return NULL;
}

const char *hud_parser_extractor_view(char *schemat, hud_t *hud,
list_t **container)
{
    hud_view_t *current = NULL;
    list_t **list_type[2];

    DPRINT(">>>START PARSING VIEW\n");
    schemat = hud_parser_view_parser(schemat, hud, container);
    current = list_get_end((*container))->data;
    list_type[0] = &current->buttons;
    list_type[1] = &current->views;
    schemat = hud_parser_extractor_view_extract(schemat, hud, list_type);
    return schemat;
}

int hud_parser_extractor(char *schemat, hud_t *hud)
{
    int type = 0;
    list_t **list_type[] = {&hud->buttons, &hud->views};

    while (schemat != NULL && schemat[0] != '\0') {
        schemat = hud_parser_extractor_ignore(schemat);
        if (schemat[0] == '\0' || (schemat[1] == '\0'))
            break;
        type = hud_parser_get_balise(schemat);
        if (type == -1) {
            schemat = hud_parser_skip_tag(schemat);
            continue;
        }
        schemat = &schemat[my_strlen(balises[type])];
        schemat = balises_func[type](schemat, hud, list_type[type]);
    }
    if (schemat != NULL) {
        DPRINT("=================HUD PARSING SUCCESSFUL=================\n\n");
    } else
        DPRINTR("=================HUD PARSING FAILED=================\n\n");
    return 0;
}
