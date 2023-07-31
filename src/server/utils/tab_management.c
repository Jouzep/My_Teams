/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** tab_management
*/

#include "server.h"

static bool only_spaces(char *str)
{
    for (unsigned long i = 0; i < strlen(str); i++) {
        if (str[i] != ' ')
            return false;
    }
    return true;
}

char **remove_empty_string(char **tab)
{
    char **stock = malloc(sizeof(char*) * (get_tab_size(tab) + 1));
    int b = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (only_spaces(tab[i]) == false) {
            stock[b] = malloc(sizeof(char) * (strlen(tab[i]) + 1));
            strcpy(stock[b], tab[i]);
            printf("tabss[%s]\n", stock[b]);
            b++;
        }
    }
    stock[b] = NULL;
    free_array(tab);
    return stock;
}
