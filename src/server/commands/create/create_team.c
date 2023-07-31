/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "server.h"

static void fill_response_struct_good(server_t *ftp
    , response_t *data, int)
{
    strcpy(data->team_name, ftp->save.teams[ftp->save.n_teams].team_name);
    strcpy(data->team_uuid, ftp->save.teams[ftp->save.n_teams].team_uuid);
    strcpy(data->team_description,
        ftp->save.teams[ftp->save.n_teams].team_description);
    data->cmd_id = CREATE;
    data->error = NO;
    data->total_messages_exchanged = 0;
}

void add_team(server_t *ftp, data_t *data, response_t *response, int client)
{
    char *uuid = gen_uuid();

    strcpy(ftp->save.teams[ftp->save.n_teams].team_uuid, uuid);
    strcpy(ftp->save.teams[ftp->save.n_teams].team_name,
        ftp->tab_cmd[1]);
    strcpy(ftp->save.teams[ftp->save.n_teams].team_description,
        ftp->tab_cmd[2]);
    strcpy(ftp->save.teams[ftp->save.n_teams].creator_uuid,
        data->client_uuid);

    fill_response_struct_good(ftp, response, ftp->save.n_teams);
    ftp->save.teams =
        realloc(ftp->save.teams, sizeof(teams_t) * (ftp->save.n_teams + 2));
    malloc_new_team(ftp);
    server_event_team_created(uuid, ftp->tab_cmd[1], data->client_uuid);
    free(uuid);
    send_team(ftp, response, client);
    return;
}

static void fill_response_struct_bad(server_t *ftp,
    response_t *data, int err_code)
{
    (void) ftp;
    data->error = err_code;
    data->cmd_id = CREATE;
    data->total_messages_exchanged = 0;
}

void create_team(server_t *ftp, data_t *data, int client)
{
    response_t response;

    response.total_team = 0;
    if (get_tab_size(ftp->tab_cmd) == 3) {
        if (check_team_name(ftp, ftp->tab_cmd[1]) == true)
            fill_response_struct_bad(ftp, &response, ALREADY);
        else {
            add_team(ftp, data, &response, client);
        }
    } else {
        fill_response_struct_bad(ftp, &response, YES);
    }
    send_response_client(ftp, client, &response);
    return;
}
