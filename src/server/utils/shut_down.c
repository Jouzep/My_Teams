/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** shut_down
*/

#include "server.h"

void close_all_client(server_t *ftp)
{
    for (int i = 0; i != MAX_CLIENT; i++) {
        if (ftp->client[i].socket != 0) {
            close_client(ftp, i);
        }
    }
    close(ftp->server.socket);
}

void free_subscribed(server_t *ftp)
{
    for (int i = 0; i != ftp->save.n_user; i++)
        free(ftp->save.users[i].team);
}

void free_myteams(server_t *ftp)
{
    free(ftp->client);
    free_subscribed(ftp);
    free(ftp->save.users);
    free(ftp->save.messages);
    free_array(ftp->tab_cmd);
}

void clear_myteams(server_t *ftp)
{
    close_all_client(ftp);
    free_myteams(ftp);
}
