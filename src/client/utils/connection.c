/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** connection
*/

#include "client.h"

int connect_to_server(client_t *clientData, char **argv)
{
    if (inet_pton(AF_INET, argv[1],
    &clientData->client.addr.sin_addr.s_addr) <= 0)
        return ERR_CLIENT_CONNECT;
    if (connect(clientData->client.socket,
    (struct sockaddr*)&clientData->client.addr,
    sizeof(clientData->client.addr)) < 0)
        return ERR_CLIENT_CONNECT;
    return NO_ERR;
}

void close_connection(const client_t *clientData)
{
    free_array(clientData->cmd);
    close(clientData->client.socket);
    exit(0);
}
