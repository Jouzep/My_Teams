/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** logout
*/

#include "server.h"

static void send_logout_events(server_t *ftp, response_t *response, int client)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (ftp->client[i].connected && i != client) {
            response->state = true;
            send_response_client(ftp, i, response);
        }
    }
}

void do_logout(server_t *ftp, data_t *data, int client)
{
    (void) data;
    response_t response;

    init_response(&response);
    strcpy(response.client_uuid, ftp->client[client].client_uuid);
    strcpy(response.client_name, ftp->client[client].client_name);
    response.cmd_id = LOGOUT;
    response.error = false;
    server_event_user_logged_out(response.client_uuid);
    disconnect_client(ftp, client);
    send_response_client(ftp, client, &response);
    send_logout_events(ftp, &response, client);
}
