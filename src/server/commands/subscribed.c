/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribed
*/

#include "server.h"

static void fill_reponse_struct_unknow_teams(server_t *ftp,
    response_t *response, char *teamuuid, int )
{
    int team_index = find_team_index_by_uuid(ftp, teamuuid);

    strcpy(response->teams[team_index].sub_uuid, ftp->tab_cmd[1]);
    response->error = UNKNOW;
    response->cmd_id = SUBSCRIBE;
    response->total_messages_exchanged = 0;
}

static void fill_reponse_struct_good_arg_teams(server_t *ftp,
    response_t *response, data_t *data, char *team_uuid)
{
    int user_index = get_index_user_by_uuid(ftp, data->client_uuid);

    if (check_if_team_exist(ftp, team_uuid) == false)
        fill_reponse_struct_unknow_teams(ftp, response, team_uuid, user_index);
    else {
        fill_reponse_struct_good_arg_teams_bis(ftp, response, team_uuid);
        response->error = NO;
        response->cmd_id = SUBSCRIBED;
        response->total_messages_exchanged = 0;
    }
}

static void fill_reponse_struct_good_arg_users(server_t *ftp,
    response_t *response, data_t *data)
{
    int user_index = get_index_user_by_uuid(ftp, data->client_uuid);
    int team_index = 0;

    response->total_team = ftp->save.users[user_index].n_team;
    response->teams = malloc(sizeof(subscribed_t)
    * (ftp->save.users[user_index].n_team + 1));
    for (int i = 0; i < ftp->save.users[user_index].n_team; i++) {
        strcpy(response->teams[i].sub_uuid,
            ftp->save.users[user_index].team[i].sub_uuid);
        team_index = find_team_index_by_uuid(ftp, response->teams[i].sub_uuid);
        strcpy(response->teams[i].sub_name,
            ftp->save.teams[team_index].team_name);
        strcpy(response->teams[i].sub_description,
            ftp->save.teams[team_index].team_description);
    }
    response->error = NO;
    response->cmd_id = SUBSCRIBED;
    response->total_messages_exchanged = 0;
}

static void fill_response_struct_bad_arg(server_t *ftp, response_t *response)
{
    (void) ftp;
    response->error = YES;
    response->cmd_id = SUBSCRIBED;
    response->total_messages_exchanged = 0;
}

void do_subscribed(server_t *ftp, data_t *data, int client)
{
    response_t response;
    int size = get_tab_size(ftp->tab_cmd);

    init_response(&response);
    response.cmd_id = SUBSCRIBED;
    if (size > 2)
        fill_response_struct_bad_arg(ftp, &response);
    else if (size == 1)
        fill_reponse_struct_good_arg_users(ftp, &response, data);
    else
        fill_reponse_struct_good_arg_teams(ftp, &response,
            data, ftp->tab_cmd[1]);
    send_response_client(ftp, client, &response);
    return;
}
