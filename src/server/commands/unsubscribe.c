/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** unsubscribe
*/

#include "server.h"

static void fill_response_struct_good(server_t *ftp, response_t *response)
{
    strcpy(response->team_uuid, ftp->tab_cmd[1]);
    response->error = NO;
    response->cmd_id = UNSUBCRIBE;
    response->total_messages_exchanged = 0;
}

static void fill_response_struct_unknow(server_t *ftp, response_t *response)
{
    strcpy(response->team_uuid, ftp->tab_cmd[1]);
    response->error = UNKNOW;
    response->cmd_id = UNSUBCRIBE;
    response->total_messages_exchanged = 0;
}

static void fill_response_struct_bad_arg(server_t *ftp, response_t *response)
{
    (void) ftp;
    response->error = YES;
    response->cmd_id = UNSUBCRIBE;
    response->total_messages_exchanged = 0;

}

void unsubscribe_user(server_t *ftp, data_t *data, int)
{
    int user_index = get_index_user_by_uuid(ftp, data->client_uuid);
    int team_index_end = ftp->save.users[user_index].n_team;
    int team_index = find_team_user_index_by_uuid(ftp,
        ftp->tab_cmd[1], user_index);

    server_event_user_unsubscribed(ftp->tab_cmd[1], data->client_uuid);
    strcpy(ftp->save.users[user_index].team[team_index].sub_uuid,
    ftp->save.users[user_index].team[team_index_end].sub_uuid);
    ftp->save.users[user_index].n_team--;
}

void do_unsubscribe(server_t *ftp, data_t *data, int client)
{
    int size = get_tab_size(ftp->tab_cmd);
    response_t response;

    response.total_team = 0;
    if (size != 2)
        fill_response_struct_bad_arg(ftp, &response);
    else if (check_team_user(ftp, ftp->tab_cmd[1], data->client_uuid)) {
        unsubscribe_user(ftp, data, client);
        fill_response_struct_good(ftp, &response);
    } else
        fill_response_struct_unknow(ftp, &response);
    send_response_client(ftp, client, &response);
    return;
}
