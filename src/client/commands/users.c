/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** users
*/

#include "client.h"
#include "logging_client.h"

void do_users(client_t *clientData, response_t *data)
{
    (void) clientData;

    for (int i = 0; i < data->total_clients; i++) {
        client_print_users(data->users[i].client_uuid,
        data->users[i].client_name, data->users[i].connected);
    }
}
