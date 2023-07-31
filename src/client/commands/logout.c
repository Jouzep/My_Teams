/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** logout
*/

#include "client.h"

void do_logout(client_t *clientData, response_t *data)
{
    if (data->state) {
        client_event_logged_out(data->client_uuid, data->client_name);
        return;
    }
    client_event_logged_out(clientData->client.client_uuid,
        clientData->client.client_name);
    strcpy(clientData->client.client_name, "");
    strcpy(clientData->client.client_uuid, "");
    if (data->error == false)
        clientData->client.connected = false;
}
