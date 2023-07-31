/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** check_arg
*/

#include <stdbool.h>
#include <stdlib.h>
#include "server.h"

int check_port(char *str)
{
    int i = 0;

    if (str[0] == '-')
        return ERR_PORT;
    for (; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return ERR_PORT;
    }
    if (atoi(str) == 0)
        return ERR_PORT;
    return NO_ERR;
}

int check_arg(char *str)
{
    int ret = 0;

    if (display_usage(str) == USAGE)
        return NO_ERR;
    if (check_port(str) == ERR_PORT)
        return ERR_PORT;
    ret = my_teams((size_t)atoi(str));
    return ret;
    return NO_ERR;
}
