/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "client.h"

static void create_comment(client_t *clientData, response_t *data)
{
    (void) clientData;
    if (data->error == NO)
        client_event_thread_reply_received(data->team_uuid,
        data->thread_uuid, data->client_uuid, data->comment_body);
    else {
        if (data->error == ALREADY)
            client_error_already_exist();
    }
}

static void create_thread(client_t *clientData, response_t *data)
{
    (void) clientData;
    if (data->error == NO)
        client_print_thread_created(data->thread_uuid,
        data->client_name , data->thread_timestamp, data->thread_title,
        data->thread_body);
    else {
        if (data->error == ALREADY)
            client_error_already_exist();
    }
}

static void create_channel(client_t *clientData, response_t *data)
{
    (void) clientData;
    if (data->error == NO)
        client_print_channel_created(data->channel_uuid,
            data->channel_name, data->channel_description);
    else {
        if (data->error == ALREADY)
            client_error_already_exist();
    }
}

static void create_team(client_t *clientData, response_t *data)
{
    (void) clientData;
    if (data->error == NO)
        client_print_team_created(data->team_uuid,
            data->team_name, data->team_description);
    else {
        if (data->error == ALREADY)
            client_error_already_exist();
    }
}

void do_create(client_t *clientData, response_t *data)
{
    if (data->state)
        print_create_event(data);
    else {
        if (clientData->client.use_id == USE_DEFAULT)
            create_team(clientData, data);
        if (clientData->client.use_id == USE_TEAM)
            create_channel(clientData, data);
        if (clientData->client.use_id == USE_CHANNEL)
            create_thread(clientData, data);
        if (clientData->client.use_id == USE_THREAD)
            create_comment(clientData, data);
    }
    return;
}
