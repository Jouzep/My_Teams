/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** send_create_event
*/

#include "server.h"

void send_team(server_t *ftp, response_t *response, int client)
{
    response->state = true;
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (i != client && ftp->client[i].socket != 0
            && ftp->client[i].connected == true) {
            response->cmd_id = CREATE;
            response->use_id = USE_DEFAULT;
            send_response_client(ftp, i, response);
        }
    }
}

void send_channel(server_t *ftp, response_t *response, int client)
{
    response->state = true;
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (i != client && ftp->client[i].socket != 0
                && ftp->client[i].connected == true
                && check_if_in_team(ftp->save.users[i],
                response->team_uuid) == true) {
            response->cmd_id = CREATE;
            response->use_id = USE_TEAM;
            send_response_client(ftp, i, response);
        }
    }
}

void send_thread(server_t *ftp, response_t *response, int client)
{
    response->state = true;
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (i != client && ftp->client[i].socket != 0
                && ftp->client[i].connected == true
                && check_if_in_team(ftp->save.users[i],
                response->team_uuid) == true) {
            response->cmd_id = CREATE;
            response->use_id = USE_CHANNEL;
            send_response_client(ftp, i, response);
        }
    }
}
