/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "server.h"

static void fill_thread_into_response(response_t *response, thread_t *thread)
{
    strcpy(response->thread_body, thread->thread_description);
    strcpy(response->thread_uuid, thread->thread_uuid);
    strcpy(response->thread_title, thread->thread_name);
    strcpy(response->client_uuid, thread->creator_uuid);
    response->thread_timestamp = thread->thread_timestamp;
}

static void fill_newthread(char **cmd, thread_t *thread, data_t *data)
{
    char *uuid = gen_uuid();
    time_t timestamp = time(NULL);

    strcpy(thread->thread_name, cmd[1]);
    strcpy(thread->thread_description, cmd[2]);
    strcpy(thread->thread_uuid, uuid);
    strcpy(thread->creator_uuid, data->client_uuid);
    thread->thread_timestamp = timestamp;
    server_event_thread_created(
    data->channel_uuid, uuid, data->client_uuid, cmd[1], cmd[2]);
    free(uuid);
}

static void add_thread(char **cmd, channel_t *channel, data_t *data,
response_t *response)
{
    fill_newthread(cmd, &channel->thread[channel->n_thread], data);
    channel->thread = realloc(channel->thread, sizeof(thread_t)
    * (channel->n_thread + 2));
    channel->n_thread++;
    malloc_comment(&channel->thread[channel->n_thread]);
    fill_thread_into_response(response,
    &channel->thread[channel->n_thread - 1]);
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
    strcpy(response->channel_description, data->channel_description);
    strcpy(response->channel_name, data->channel_name);
    strcpy(response->channel_uuid, data->channel_uuid);
}

void create_thread(server_t *ftp, data_t *data, int client)
{
    response_t response;
    int team_index = find_team_index_by_uuid(ftp, data->team_uuid);
    int channel_index = find_channel_index_by_uuid(
    &ftp->save.teams[team_index], data->channel_uuid);

    init_response_channel(&response, data);
    if (get_tab_size(ftp->tab_cmd) == 3) {
        add_thread(ftp->tab_cmd, &ftp->save.teams[team_index].
        channel[channel_index], data, &response);
        send_thread(ftp, &response, client);
    } else
        printf("ERROR ARGS\n");

    send_response_client(ftp, client, &response);
    return;
}
