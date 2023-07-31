/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** restaure_server
*/

#include "server.h"

static void restore_message(server_t *server, FILE *file)
{
    fread(&server->save.n_messages, sizeof(int), 1, file);
    server->save.messages = malloc(sizeof(messages_t)
    * (server->save.n_messages + 1));
    for (int i = 0; i != server->save.n_messages; i++) {
        fread(&server->save.messages[i], sizeof(messages_t), 1 ,file);
    }
}

static void restore_subscribed_team(server_t *server, FILE *file, int i)
{
    server->save.users[i].team =
    malloc(sizeof(subscribed_t) * (server->save.users[i].n_team + 1));
    for (int a = 0; a != server->save.users[i].n_team; a++) {
        fread(&server->save.users[i].team[a], sizeof(subscribed_t), 1, file);
        printf("\tSubscribe : [%s]\n", server->save.users[i].team[a].sub_uuid);
    }
}

static void restore_user(server_t *server, FILE *file)
{
    fread(&server->save.n_user, sizeof(int), 1, file);
    server->save.users =
    malloc(sizeof(users_t) * (server->save.n_user + 1));
    for (int i = 0; i != server->save.n_user; i++) {
        fread(&server->save.users[i], sizeof(users_t), 1 ,file);
        server_event_user_loaded(server->save.users[i].client_uuid,
            server->save.users[i].client_name);
        restore_subscribed_team(server, file, i);
    }
}

void restaure_server(server_t *server)
{
    FILE *file = fopen("save.dat", "rb");

    if (file != NULL) {
        restore_user(server, file);
        restore_message(server, file);
        restore_team(server, file);
        fclose(file);
    } else {
        default_user(server);
        default_message(server);
        default_team(server);
    }
}
