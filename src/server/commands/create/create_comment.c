/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "server.h"

static void fill_thread_into_response(response_t *response, comment_t *comment)
{
    strcpy(response->comment_body, comment->comment_description);
    strcpy(response->comment_uuid, comment->comment_uuid);
    strcpy(response->client_uuid, comment->creator_uuid);
    response->comment_timestamp = comment->comment_timestamp;
}

static void fill_newcomment(char **cmd, comment_t *comment, data_t *data)
{
    char *uuid = gen_uuid();
    time_t timestamp = time(NULL);

    strcpy(comment->comment_description, cmd[1]);
    strcpy(comment->comment_uuid, uuid);
    strcpy(comment->creator_uuid, data->client_uuid);
    comment->comment_timestamp = timestamp;
    server_event_reply_created(uuid, comment->creator_uuid,
    comment->comment_description);
    free(uuid);
}

static void add_comment(char **cmd, thread_t *thread, data_t *data,
response_t *response)
{
    fill_newcomment(cmd, &thread->comment[thread->n_comment], data);
    thread->comment = realloc(thread->comment, sizeof(comment_t) *
    (thread->n_comment + 2));
    thread->n_comment = thread->n_comment + 1;
    fill_thread_into_response(response,
    &thread->comment[thread->n_comment - 1]);
}

static void init_response_channel(response_t *response, data_t *data)
{
    response->cmd_id = CREATE;
    response->error = NO;
    response->total_messages_exchanged = 0;
    response->total_team = 0;
    response->thread_timestamp = data->thread_timestamp;
    strcpy(response->team_description, data->team_description);
    strcpy(response->team_name, data->team_name);
    strcpy(response->team_uuid, data->team_uuid);
    strcpy(response->channel_description, data->channel_description);
    strcpy(response->channel_name, data->channel_name);
    strcpy(response->channel_uuid, data->channel_uuid);
    strcpy(response->thread_title, data->thread_title);
    strcpy(response->thread_body, data->thread_body);
    strcpy(response->thread_uuid, data->thread_uuid);
}

void create_comment(server_t *ftp, data_t *data, int client)
{
    response_t response;
    int team_index = find_team_index_by_uuid(ftp, data->team_uuid);
    int channel_index = find_channel_index_by_uuid(
    &ftp->save.teams[team_index], data->channel_uuid);
    int thread_index = find_thread_index_by_uuid(&ftp->save.teams[team_index].
    channel[channel_index], data->thread_uuid);

    init_response_channel(&response, data);
    if (get_tab_size(ftp->tab_cmd) == 2) {
        add_comment(ftp->tab_cmd, &ftp->save.teams[team_index].
        channel[channel_index].thread[thread_index], data, &response);
    } else
        printf("ERROR ARGS\n");
    send_response_client(ftp, client, &response);
    return;
}
