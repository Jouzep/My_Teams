/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** quote
*/

#include "client.h"

static bool externe_space(char c, bool res)
{
    if ((c != ' ' && c != '\"'))
        return false;
    return res;
}

static bool externe_quote(char *str, int *quote)
{
    bool res = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\"')
            *quote = *quote + 1;
        if (*quote % 2 == 0)
            res = externe_space(str[i], res);
    }
    return res;
}

bool check_input(char **str)
{
    int quote = 0;
    int i = 1;
    bool ret = true;

    if (str[0] == NULL)
        return false;
    for (; str[i] != NULL; i++)
        if (externe_quote(str[i], &quote) == false)
            ret = false;
    if (quote % 2 == 1)
        ret = false;
    if (quote == 0 && get_tab_size(str) != 1)
        ret = false;
    free_array(str);
    printf("%d", ret);
    return ret;
}
