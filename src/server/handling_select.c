/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** handling_select
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

void set_fdset(server_t *ftp)
{
    FD_ZERO(&ftp->r_set);
    FD_SET(ftp->server.socket, &ftp->r_set);
    for (int i = 0; i != MAX_CLIENT; i++) {
        if (ftp->client[i].socket > 0) {
            FD_SET(ftp->client[i].socket, &ftp->r_set);
        }
    }
}

int do_select(server_t *ftp)
{
    if (select(FD_SETSIZE, &ftp->r_set, NULL, NULL, NULL) < 0)
        return ERR_SELECT;
    manage_select(ftp);
    return NO_ERR;
}

int manage_select(server_t *ftp)
{
    int ret = NO_ERR;

    if (FD_ISSET(ftp->server.socket, &ftp->r_set))
        ret = add_client(ftp);
    else
        read_client(ftp);
    return ret;
}
