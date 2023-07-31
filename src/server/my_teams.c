/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** my_teams
*/

#include "server.h"

int my_teams_loop(server_t *ftp)
{
    while (1) {
        set_fdset(ftp);
        do_select(ftp);
    }
}

int my_teams(int port)
{
    server_t ftp;
    int ret = NO_ERR;

    FD_ZERO(&ftp.r_set);
    if ((ret = init_server(&ftp, port)) != NO_ERR)
        return ret;
    ret = my_teams_loop(&ftp);
    return ret;
}
