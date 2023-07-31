/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** use
*/

#include "client.h"

static void use_error(client_t *, response_t *data)
{
    if (data->error == UNKNOW)
        client_error_unknown_team(data->team_uuid);
    if (data->error == UNAUTHORIZED)
        client_error_unauthorized();
}

static void set_use_team_bis(client_t *clientData, response_t *data)
{
    if (data->use_id >= USE_CHANNEL) {
        clientData->client.use_id = USE_CHANNEL;
        strcpy(clientData->client.channel_name, data->channel_name);
        strcpy(clientData->client.channel_uuid, data->channel_uuid);
        strcpy(clientData->client.channel_description,
        data->channel_description);
    }
    if (data->use_id >= USE_THREAD) {
        clientData->client.use_id = USE_THREAD;
        strcpy(clientData->client.thread_title, data->thread_title);
        strcpy(clientData->client.thread_uuid, data->thread_uuid);
        strcpy(clientData->client.thread_body, data->thread_body);
    }
}

static void set_use_team(client_t *clientData, response_t *data)
{
    clientData->client.use_id = USE_DEFAULT;
    if (data->use_id >= USE_TEAM) {
        clientData->client.use_id = USE_TEAM;
        strcpy(clientData->client.team_name, data->team_name);
        strcpy(clientData->client.team_uuid, data->team_uuid);
        strcpy(clientData->client.team_description, data->team_description);
    }
    set_use_team_bis(clientData, data);
}

void do_use(client_t *clientData, response_t *data)
{
    (void) clientData;
    (void) data;
    if (data->error == NO)
        set_use_team(clientData, data);
    else
        use_error(clientData, data);
    return;
}
