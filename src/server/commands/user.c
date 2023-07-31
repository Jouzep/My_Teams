/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** user
*/

#include "server.h"

static void get_user_informations
(server_t *ftp, response_t *response, char *uuid_to_find)
{
    for (int i = 0; i < ftp->save.n_user; i++) {
        if (strcmp(ftp->save.users[i].client_uuid,
        uuid_to_find) == 0) {
            strcpy(response->user_informations.client_name,
            ftp->save.users[i].client_name);
            strcpy(response->user_informations.client_uuid,
            ftp->save.users[i].client_uuid);
            break;
        }
    }
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (strcmp(ftp->client[i].client_uuid,
        response->user_informations.client_uuid) == 0) {
            response->user_informations.connected = true;
            break;
        } else
            response->user_informations.connected = false;
    }
}

void do_user(server_t *ftp, data_t *data, int client)
{
    response_t response;

    init_response(&response);
    strcpy(response.client_name, data->client_name);
    strcpy(response.client_uuid, data->client_uuid);
    response.cmd_id = USER;
    if (get_tab_size(ftp->tab_cmd) != 2) {
        response.error = true;
        send_response_client(ftp, client, &response);
        return;
    }
    if (!check_if_user_exist(ftp, &response, ftp->tab_cmd[1])) {
        send_response_client(ftp, client, &response);
        return;
    }
    get_user_informations(ftp, &response, ftp->tab_cmd[1]);
    response.error = false;
    send_response_client(ftp, client, &response);
}
