/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create_bis
*/

#include "client.h"

void print_create_event(response_t *data)
{
    if (data->use_id == USE_DEFAULT) {
        client_event_team_created(data->team_uuid,
            data->team_name, data->team_description);
        return;
    } else if (data->use_id == USE_TEAM) {
        client_event_channel_created(data->channel_uuid,
            data->channel_name, data->channel_description);
        return;
    } else {
        client_event_thread_created(data->thread_uuid,
            data->client_uuid, data->thread_timestamp,
            data->thread_title, data->thread_body);
        return;
    }
}
