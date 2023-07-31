/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** check_arg
*/


#include <stdlib.h>
#include <stdbool.h>
#include "client.h"

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

int check_arg(char **av, int ac)
{
    if (display_usage(av[1]) == USAGE)
        return NO_ERR;
    if (ac != 3)
        return ERR_ARGS;
    if (check_port(av[2]) == ERR_PORT)
        return ERR_PORT;
    return my_teams(av);
}
