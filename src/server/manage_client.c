/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** manage_client
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "server.h"

int add_client(server_t *ftp)
{
    ftp->tmp.socket = accept(ftp->server.socket,
    (struct sockaddr *)&ftp->tmp.addr, (socklen_t *)&ftp->addrlen);
    if (ftp->tmp.socket < 0)
        return ERR_ACCEPT;
    for (int i = 0; i != MAX_CLIENT; i++) {
        if (ftp->client[i].socket == 0) {
            ftp->client[i].socket = ftp->tmp.socket;
            ftp->client[i].addr = ftp->tmp.addr;
            break;
        }
    }
    return NO_ERR;
}

void close_client(server_t *ftp, int client)
{
    close(ftp->client[client].socket);
    ftp->client[client].socket = 0;
    ftp->client[client].connected = false;
    ftp->client[client].use_id = USE_TEAM;
    ftp->client[client].client_name[0] = '\0';
    ftp->client[client].client_uuid[0] = '\0';
}

void disconnect_client(server_t *ftp, int client)
{
    strcpy(ftp->client[client].client_name, "");
    strcpy(ftp->client[client].client_uuid, "");
    ftp->client[client].connected = false;
}

void read_single_client(server_t *ftp, int client)
{
    size_t val = 0;
    char str[sizeof(data_t)];

    if (FD_ISSET(ftp->client[client].socket, &ftp->r_set)) {
        val = recv(ftp->client[client].socket, str, sizeof(data_t), 0);
        if (val == 0) {
            close_client(ftp, client);
        } else {
            parse_client_response(ftp, client, str);
        }
    }
}

void read_client(server_t *ftp)
{
    for (int i = 0; i != MAX_CLIENT; i++) {
        read_single_client(ftp, i);
    }
}
