/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** my_teams
*/

#include "client.h"


int fill_struct(client_t *clientData, char **arg)
{
    clientData->cmd = str_word_array("");
    clientData->client.connected = false;
    clientData->client.client_name[0] = '\0';
    clientData->client.client_uuid[0] = '\0';
    clientData->client.use_id = USE_DEFAULT;
    return init_socket(&clientData->client, arg);
}

int client_loop(client_t *clientData)
{
    while (1) {
        set_fdset(clientData);
        do_select(clientData);
    }
    close(clientData->client.socket);
    return NO_ERR;
}

int my_teams(char **arg)
{
    client_t clientData;

    init_signal(&clientData);
    if (fill_struct(&clientData, arg) == ERR_SOCKET)
        return ERR_CLIENT_SOCKET;
    if (connect_to_server(&clientData, arg) == ERR_CLIENT_CONNECT)
        return ERR_CLIENT_CONNECT;
    client_loop(&clientData);
    return NO_ERR;
}
