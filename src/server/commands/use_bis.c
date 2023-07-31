/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** use_bis
*/

#include "server.h"

static void fill_thread(server_t *ftp, response_t *response, int size)
{
    int channel_index;
    int team_index;
    int thread_index;

    if (size >= USE_THREAD) {
        response->use_id = USE_THREAD;
        team_index = find_team_index_by_uuid(ftp, ftp->tab_cmd[1]);
        channel_index = find_channel_index_by_uuid(
        &ftp->save.teams[team_index], ftp->tab_cmd[2]);
        thread_index = find_thread_index_by_uuid(
        &ftp->save.teams[team_index].channel[channel_index], ftp->tab_cmd[3]);
        strcpy(response->thread_body, ftp->save.teams[team_index]
        .channel[channel_index].thread[thread_index].thread_description);
        strcpy(response->thread_title, ftp->save.teams[team_index].
        channel[channel_index].thread[thread_index].thread_name);
        strcpy(response->thread_uuid, ftp->save.teams[team_index].
        channel[channel_index].thread[thread_index].thread_uuid);
        response->thread_timestamp = ftp->save.teams[team_index].
        channel[channel_index].thread[thread_index].thread_timestamp;
    }
}

static void fill_channel(server_t *ftp, response_t *response, int size)
{
    int channel_index;
    int team_index;

    if (size >= USE_CHANNEL) {
        team_index = find_team_index_by_uuid(ftp, ftp->tab_cmd[1]);
        channel_index = find_channel_index_by_uuid(
        &ftp->save.teams[team_index], ftp->tab_cmd[2]);
        response->use_id = USE_CHANNEL;
        strcpy(response->channel_name, ftp->save.teams[team_index].
        channel[channel_index].channel_name);
        strcpy(response->channel_description, ftp->save.teams[team_index].
        channel[channel_index].channel_description);
        strcpy(response->channel_uuid, ftp->tab_cmd[2]);
    }
}

static void fill_team(server_t *ftp, response_t *response, int size)
{
    int team_index;

    if (size >= USE_TEAM) {
        team_index = find_team_index_by_uuid(ftp, ftp->tab_cmd[1]);
        response->use_id = USE_TEAM;
        strcpy(response->team_uuid, ftp->tab_cmd[1]);
        strcpy(response->team_name, ftp->save.teams[team_index].team_name);
        strcpy(response->team_description,
        ftp->save.teams[team_index].team_description);
    }
}

void fill_use(server_t *ftp, response_t *response, int size)
{
    fill_team(ftp, response, size);
    fill_channel(ftp, response, size);
    fill_thread(ftp, response, size);
}
