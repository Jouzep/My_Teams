/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** restore_team
*/

#include "server.h"

static void restore_comment(thread_t *thread, FILE *file)
{
    fread(&thread->n_comment, sizeof(int), 1, file);
    thread->comment = malloc(sizeof(channel_t) * (thread->n_comment + 1));
    for (int i = 0; i != thread->n_comment; i++) {
        fread(&thread->comment[i], sizeof(comment_t), 1, file);
        printf("\t\t\t Comment : [%s] [%s] [%s]\n",
        thread->comment[i].comment_description,
        thread->comment[i].comment_uuid
        ,thread->comment[i].creator_uuid);
    }
}

static void restore_thread(channel_t *channel, FILE *file)
{
    fread(&channel->n_thread, sizeof(int), 1, file);
    channel->thread = malloc(sizeof(channel_t) * (channel->n_thread + 1));
    for (int i = 0; i != channel->n_thread; i++) {
        fread(&channel->thread[i], sizeof(thread_t), 1, file);
        printf("\t\t Thread : [%s] [%s] [%s]\n", channel->thread[i].thread_name,
        channel->thread[i].thread_description, channel->thread[i].thread_uuid);
        restore_comment(&channel->thread[i], file);
    }
}

static void restore_channel(teams_t *team, FILE *file)
{
    fread(&team->n_channel, sizeof(int), 1, file);
    team->channel = malloc(sizeof(channel_t) * (team->n_channel + 1));
    for (int i = 0; i != team->n_channel; i++) {
        fread(&team->channel[i], sizeof(channel_t), 1, file);
        printf("\t Channel : [%s] [%s] [%s]\n", team->channel[i].channel_name,
        team->channel[i].channel_description, team->channel[i].channel_uuid);
        restore_thread(&team->channel[i], file);
    }
}

void restore_team(server_t *server, FILE *file)
{
    fread(&server->save.n_teams, sizeof(int), 1, file);
    server->save.teams =
    malloc(sizeof(teams_t) * (server->save.n_teams + 1));
    for (int i = 0; i != server->save.n_teams; i++) {
        fread(&server->save.teams[i], sizeof(teams_t), 1 ,file);
        printf("Team %d Loaded = [%s], [%s], [%s]\n", i,
        server->save.teams[i].team_name,
        server->save.teams[i].team_description,
        server->save.teams[i].team_uuid);
        restore_channel(&server->save.teams[i], file);
    }
}
