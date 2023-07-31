/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** Server main
*/

#include <stdbool.h>
#include <string.h>
#include "server.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return ERR;
    return check_arg(av[1]);
}
