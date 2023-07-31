/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** user
*/


#include "client.h"

void do_user(client_t *clientData, response_t *data)
{
    (void) clientData;

    if (data->error == true)
        return;
    if (data->error == ERR_CLIENT_NO_FOUND) {
        client_error_unknown_user(data->other_uuid);
        return;
    }
    client_print_user(data->user_informations.client_uuid,
    data->user_informations.client_name, data->user_informations.connected);
}
