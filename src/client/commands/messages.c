/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** messages
*/

#include "client.h"

void do_messages(client_t *clientData, response_t *data)
{
    (void) clientData;

    if (data->error == ERR_ARGS)
        return;

    if (data->error == ERR_CLIENT_NO_FOUND) {
        client_error_unknown_user(data->other_uuid);
        return;
    }

    for (int i = 0; i < data->total_messages_exchanged; i++) {
        client_private_message_print_messages(
                data->messages_exchanged[i].uuid_client,
                data->messages_exchanged[i].message_timestamp,
                data->messages_exchanged[i].body_message);
    }
}
