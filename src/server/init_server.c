/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** init_server
*/

#include <stdlib.h>
#include "server.h"

int init_clients_socket(server_t *ftp)
{
    ftp->client = malloc(sizeof(socket_t) * MAX_CLIENT);
    if (ftp->client == NULL)
        return ERR_CLIENT_MALLOC;
    for (int i = 0; i != MAX_CLIENT; i++) {
        ftp->client[i].socket = 0;
        strcpy(ftp->client[i].client_name, "");
        strcpy(ftp->client[i].client_uuid, "");
        ftp->client[i].use_id = USE_DEFAULT;
    }
    return NO_ERR;
}

int init_server_socket(server_t *ftp, int port)
{
    if (init_socket(&ftp->server, port) == ERR_SOCKET)
        return ERR_SERV_SOCKET;
    if (bind_socket(&ftp->server) == ERR_BIND)
        return ERR_SERV_BIND;
    if (listen_socket(&ftp->server) == ERR_LISTEN)
        return ERR_SERV_LISTEN;
    return NO_ERR;
}

int init_server(server_t *ftp, size_t port)
{
    int ret = 0;

    init_signal(ftp);
    ret = init_server_socket(ftp, port);
    if (ret != NO_ERR)
        return ret;
    if (init_clients_socket(ftp) == ERR_CLIENT_MALLOC)
        return ERR_CLIENT_MALLOC;
    ftp->addrlen = sizeof(ftp->server.addr);
    ftp->tab_cmd = str_word_array("");
    restaure_server(ftp);
    return NO_ERR;
}
