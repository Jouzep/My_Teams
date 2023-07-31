/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** login
*/

#include <uuid/uuid.h>
#include "client.h"

void do_login(client_t *clientData, response_t *data)
{
    if (data->state) {
        client_event_logged_in(data->client_uuid,
            data->client_name);
        return;
    }
    if (data->error == ERR_CLIENT_CONNECT) {
        printf("Client already connected !\n");
        return;
    }
    strcpy(clientData->client.client_name, data->client_name);
    strcpy(clientData->client.client_uuid, data->client_uuid);
    if (data->error == false)
        clientData->client.connected = true;
    client_event_logged_in(clientData->client.client_uuid,
        clientData->client.client_name);
}
