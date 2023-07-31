/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** send
*/

#include "client.h"

void do_send(client_t *clientData, response_t *data)
{
    (void) clientData;

    if (data->error == ERR_CLIENT_NO_FOUND) {
        client_error_unknown_user(data->other_uuid);
        return;
    }
    if (data->state) {
        client_event_private_message_received(data->client_uuid, data->message);
    }
}
