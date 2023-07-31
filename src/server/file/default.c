/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** default
*/

#include "server.h"

void default_user(server_t *server)
{
    server->save.users = malloc(sizeof(users_t) * 1);
    server->save.n_user = 0;
    server->save.users[0].team = malloc(sizeof(subscribed_t) * 1);
    server->save.n_teams = 0;
}

void default_message(server_t *server)
{
    server->save.messages = malloc(sizeof(messages_t) * 1);
    server->save.n_messages = 0;
}

void default_team(server_t *server)
{
    server->save.teams = malloc(sizeof(teams_t) * 1);
    server->save.n_teams = 0;
    server->save.teams[0].channel = malloc(sizeof(channel_t) * 1);
    server->save.teams[0].n_channel = 0;
    server->save.teams[0].channel[0].thread = malloc(sizeof(thread_t) * 1);
    server->save.teams[0].channel[0].n_thread = 0;
    server->save.teams[0].channel[0].thread[0].comment =
    malloc(sizeof(comment_t) * 1);
    server->save.teams[0].channel[0].thread[0].n_comment = 0;
}
