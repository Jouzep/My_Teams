/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** users
*/

#include "server.h"

static void get_all_users(server_t *ftp, response_t *response)
{
    int j = 0;

    for (int i = 0; i < ftp->save.n_user; i++, j++) {
        strcpy(response->users[j].client_name, ftp->save.users[i].client_name);
        strcpy(response->users[j].client_uuid, ftp->save.users[i].client_uuid);
        response->users[j].connected = false;
    }
    response->total_clients = j;
}

static void check_is_connected(server_t *ftp, response_t *response, int i,
int j)
{
    if (strcmp(ftp->client[j].client_uuid,
        response->users[i].client_uuid) == 0) {
        response->users[i].connected = true;
    }
}

void do_users(server_t *ftp, data_t *data, int client)
{
    response_t response;

    init_response(&response);
    get_all_users(ftp, &response);
    for (int j = 0; j < MAX_CLIENT; j++) {
        for (int i = 0; i < response.total_clients; i++) {
            check_is_connected(ftp, &response, i, j);
        }
    }
    response.cmd_id = USERS;
    response.error = false;
    strcpy(response.client_uuid, data->client_uuid);
    strcpy(response.client_name, data->client_name);
    send_response_client(ftp, client, &response);
}
