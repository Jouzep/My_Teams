/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** save_team
*/

#include "server.h"

static void save_comment(thread_t *thread, FILE *file)
{
    fwrite(&thread->n_comment, sizeof(int), 1, file);
    for (int i = 0; i != thread->n_comment; i++) {
        printf("--- --- --- Comment : [%s] [%s]\n",
        thread->comment[i].comment_description,
        thread->comment[i].comment_uuid);
        fwrite(&thread->comment[i], sizeof(comment_t), 1, file);
    }
    free(thread->comment);
}

static void save_thread(channel_t *channel, FILE *file)
{
    fwrite(&channel->n_thread, sizeof(int), 1, file);
    for (int i = 0; i != channel->n_thread; i++) {
        fwrite(&channel->thread[i], sizeof(thread_t), 1, file);
        printf("--- --- Thread : [%s] [%s]\n", channel->thread[i].thread_name,
        channel->thread[i].thread_description);
        save_comment(&channel->thread[i], file);
    }
    free(channel->thread);
}

static void save_channel(teams_t *team, FILE *file)
{
    fwrite(&team->n_channel, sizeof(int), 1, file);
    for (int i = 0; i != team->n_channel; i++) {
        fwrite(&team->channel[i], sizeof(channel_t), 1, file);
        printf("--- Channel : [%s] [%s]\n", team->channel[i].channel_name,
        team->channel[i].channel_description);
        save_thread(&team->channel[i], file);
    }
    free(team->channel);
}

void save_team(server_t *ftp, FILE *file)
{
    fwrite(&ftp->save.n_teams, sizeof(int), 1, file);
    for (int i = 0; i != ftp->save.n_teams; i++) {
        fwrite(&ftp->save.teams[i], sizeof(teams_t), 1 ,file);
        save_channel(&ftp->save.teams[i], file);
        printf("Team : [%s] [%s]\n", ftp->save.teams[i].team_name,
        ftp->save.teams[i].team_description);
    }
    free(ftp->save.teams);
}
