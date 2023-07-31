/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** select
*/

#include "client.h"

void set_fdset(client_t *clientData)
{
    FD_ZERO(&clientData->r_set);
    FD_SET(STDIN_FILENO, &clientData->r_set);
    FD_SET(clientData->client.socket, &clientData->r_set);
}

int do_select(client_t *clientData)
{
    if (select(FD_SETSIZE, &clientData->r_set, NULL, NULL, NULL) < 0)
        return ERR_SELECT;
    if (FD_ISSET(STDIN_FILENO, &clientData->r_set)) {
        parse_client_response(clientData);
    }
    if (FD_ISSET(clientData->client.socket, &clientData->r_set)) {
        server_response(clientData);
    }
    return NO_ERR;
}
