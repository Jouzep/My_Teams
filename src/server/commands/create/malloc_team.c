/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** malloc_team
*/

#include "server.h"

void malloc_comment(thread_t *thread)
{
    thread->n_comment = 0;
    thread->comment = malloc(sizeof(commands_t) * 1);
}

void malloc_thread(channel_t *channel)
{
    channel->thread = malloc(sizeof(thread_t) * 1);
    channel->n_thread = 0;
    malloc_comment(&channel->thread[0]);
}

void malloc_channel(teams_t *team)
{
    team->channel = malloc(sizeof(channel_t) * 1);
    team->n_channel = 0;
    malloc_thread(&team->channel[0]);
}

void malloc_new_team(server_t *ftp)
{
    int new_index = ftp->save.n_teams + 1;

    ftp->save.n_teams++;
    malloc_channel(&ftp->save.teams[new_index]);
}
