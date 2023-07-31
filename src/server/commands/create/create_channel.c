/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "server.h"

static void fill_channel_into_response(response_t *response, channel_t *channel)
{
    strcpy(response->channel_description, channel->channel_description);
    strcpy(response->channel_name, channel->channel_name);
    strcpy(response->channel_uuid, channel->channel_uuid);
}

void add_channel(server_t *ftp, data_t *data, response_t *response, int client)
{
    int team_index = find_team_index_by_uuid(ftp, data->team_uuid);
    int channel_index = ftp->save.teams[team_index].n_channel;

    fill_newchannel(ftp->tab_cmd, &ftp->save.teams[team_index].
    channel[channel_index], data);
    ftp->save.teams[team_index].channel = realloc(ftp->save.teams[team_index].
    channel, sizeof(channel_t) * (channel_index + 2));
    ftp->save.teams[team_index].n_channel = ftp->save.teams[team_index]
    .n_channel + 1;
    malloc_thread(&ftp->save.teams[team_index].channel
    [ftp->save.teams[team_index].n_channel]);
    fill_channel_into_response(response,
    &ftp->save.teams[team_index].channel[channel_index]);
    send_channel(ftp, response, client);
}

void fill_newchannel(char **cmd, channel_t *channel, data_t *data)
{
    char *uuid = gen_uuid();

    strcpy(channel->channel_uuid, uuid);
    strcpy(channel->channel_name, cmd[1]);
    strcpy(channel->channel_description, cmd[2]);
    strcpy(channel->creator_uuid, data->client_uuid);
    server_event_channel_created(data->team_uuid, channel->channel_uuid,
    channel->channel_name);
    free(uuid);
}

static void init_response_channel(response_t *response, data_t *data)
{
    response->cmd_id = CREATE;
    response->error = NO;
    response->total_messages_exchanged = 0;
    response->total_team = 0;
    strcpy(response->team_description, data->team_description);
    strcpy(response->team_name, data->team_name);
    strcpy(response->team_uuid, data->team_uuid);
}

void create_channel(server_t *ftp, data_t *data, int client)
{
    response_t response;

    init_response_channel(&response, data);
    if (get_tab_size(ftp->tab_cmd) == 3) {
        add_channel(ftp, data, &response, client);
    } else
        printf("Error args");
    send_response_client(ftp, client, &response);
    return;
}
