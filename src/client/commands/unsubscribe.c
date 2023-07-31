/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** unsubscribe
*/

#include "client.h"

static void unsubscribe_succes(client_t *, response_t *data)
{
    client_print_unsubscribed(data->client_uuid, data->team_uuid);
}

static void unsubscribe_error(client_t *, response_t *data)
{
    if (data->error == UNKNOW)
        client_error_unknown_team(data->team_uuid);
    if (data->error == UNAUTHORIZED)
        client_error_unauthorized();
}

void do_unsubscribe(client_t *clientData, response_t *data)
{
    if (data->error == NO)
        unsubscribe_succes(clientData, data);
    else
        unsubscribe_error(clientData, data);
}
