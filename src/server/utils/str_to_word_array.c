/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-server-joseph.yu
** File description:
** str_to_word_array
*/

#include "server.h"

int get_tab_size(char **str)
{
    int i = 0;
    while (str[i] != NULL)
        i++;
    return i;
}

int count_word(char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\"')
            size++;
    }
    return size;
}

void free_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

char **str_word_array(char *str)
{
    int size = count_word(str) + 1;
    char **tab = malloc(sizeof(char *) * (size + 1));
    char *token = strtok(str, " ");
    int i = 0;

    for (i = 0; token != NULL; i++) {
        tab[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tab[i], token);
        tab[i][strlen(token)] = '\0';
        token = strtok(NULL, "\"");
    }
    tab[i] = NULL;
    return tab;
}
