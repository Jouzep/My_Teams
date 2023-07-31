/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribe
*/

#include "client.h"

static void error_subscribe(response_t *data)
{
    if (data->error == UNKNOW)
        client_error_unknown_team(data->team_uuid);
    if (data->error == ALREADY)
        client_error_already_exist();
}

void do_subscribe(client_t *clientData, response_t *data)
{
    if (data->error == NO)
        client_print_subscribed(clientData->client.client_uuid,
            data->team_uuid);
    else
        error_subscribe(data);
    return;
}
