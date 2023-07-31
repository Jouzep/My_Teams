/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** usage
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int display_usage(char *str)
{
    if (strcmp(str, "-help") == 0) {
        printf("USAGE: ./myteams_cli ip port\n");
        printf("\tip\tis the server ip ");
        printf("address on which the server socket listens\n");
        printf("\tport\tis the port number on which the");
        printf(" server socket listens\n");
        return USAGE;
    }
    return NO_ERR;
}
