/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** login_bis
*/

#include "server.h"
#include "commun.h"

void send_login_events(server_t *ftp, response_t *response, int client)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (ftp->client[i].socket != 0 &&
            ftp->client[i].connected && i != client) {
            response->state = true;
            send_response_client(ftp, i, response);
        }
    }
}
