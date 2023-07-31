/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribe_bis
*/

#include "server.h"

bool already_subscribe(server_t *ftp, int user_index,
    char *team_uuid)
{
    for (int i = 0; i != ftp->save.users[user_index].n_team; i++) {
        if (strcmp(team_uuid,
            ftp->save.users[user_index].team[i].sub_uuid) == 0)
            return true;
    }
    return false;
}

void subscribe_user(server_t *ftp, data_t *data, int client)
{
    (void) client;
    int user_index = get_index_user_by_uuid(ftp, data->client_uuid);
    int team_index = ftp->save.users[user_index].n_team;

    strcpy(ftp->save.users[user_index].team[team_index].sub_uuid,
        ftp->tab_cmd[1]);
    server_event_user_subscribed(ftp->tab_cmd[1], data->client_uuid);
    ftp->save.users[user_index].team = realloc(ftp->save.users[user_index].team,
    sizeof(teams_t) * (team_index + 2));
    ftp->save.users[user_index].n_team++;
}

static void fill_response_struct_good(server_t *ftp, response_t *response)
{
    strcpy(response->team_uuid, ftp->tab_cmd[1]);
    response->error = NO;
    response->cmd_id = SUBSCRIBE;
    response->total_messages_exchanged = 0;
}

static void fill_response_struct_already(server_t *ftp, response_t *response)
{
    (void) ftp;

    response->error = ALREADY;
    response->cmd_id = SUBSCRIBE;
    response->total_messages_exchanged = 0;
}

void check_subscription(server_t *ftp,
    response_t *response, data_t *data, int client)
{
    if (already_subscribe(ftp,
            get_index_user_by_uuid(ftp, data->client_uuid),
            ftp->tab_cmd[1]) == false) {
        subscribe_user(ftp, data, client);
        fill_response_struct_good(ftp, response);
    } else
        fill_response_struct_already(ftp, response);
}
