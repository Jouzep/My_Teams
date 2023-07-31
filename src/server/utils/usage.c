/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** help
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

int display_usage(char *str)
{
    if (strcmp(str, "-help") == 0) {
        printf("USAGE: ./myteams_server port\n");
        printf("\tport is the port number ");
        printf("on which the server socket listens.\n");
        return USAGE;
    }
    return NO_ERR;
}
