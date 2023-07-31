/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** use
*/

#include "server.h"

use_t find[] = {
    {&find_team, USE_TEAM},
    {&find_team, USE_TEAM},
    {&find_channel, USE_CHANNEL},
    {&find_thread, USE_THREAD},
};

bool check_if_subscribed(server_t *ftp, data_t *data, int)
{
    int user_index = get_index_user_by_uuid(ftp, data->client_uuid);
    char *team_uuid = ftp->tab_cmd[1];

    for (int i = 0; i != ftp->save.users[user_index].n_team; i++)
        if (strcmp(team_uuid,
            ftp->save.users[user_index].team[i].sub_uuid) == 0)
            return true;
    return false;
}

static void fill_response_struct_good(server_t *ftp,
response_t *response, data_t *, int ret)
{
    int size = get_tab_size(ftp->tab_cmd) - 1;

    response->total_messages_exchanged = 0;
    response->use_id = ret;
    response->cmd_id = USE;
    response->error = NO;

    fill_use(ftp, response, size);
}

static void fill_response_struct_bad(server_t *ftp,
    response_t *response, data_t *data, int ret)
{
    response->total_messages_exchanged = 0;
    response->use_id = data->use_id;
    response->cmd_id = USE;
    if (get_tab_size(ftp->tab_cmd) > 1)
        strcpy(response->team_uuid, ftp->tab_cmd[1]);
    response->error = YES;
    if (ret == UNKNOW)
        response->error = UNKNOW;
    if (ret == UNAUTHORIZED)
        response->error = UNAUTHORIZED;
}

int find_use(server_t *ftp, data_t *data, int client)
{
    int i = 1;
    int ret = 0;

    if (get_tab_size(ftp->tab_cmd) == 1)
        return USE_DEFAULT;
    for (; i != get_tab_size(ftp->tab_cmd) - 1; i++) {
        if (ret < 0)
            break;
        ret = find[i].func(ftp, data, client) + ret;
    }
    return ret;
}

void do_use(server_t *ftp, data_t *data, int client)
{
    response_t response;
    int size = get_tab_size(ftp->tab_cmd);
    int ret = 0;

    response.total_team = 0;
    if (data->cmd_id != USE)
        return;
    if (size > 0 && size <= 5) {
        ret = find_use(ftp, data, client);
    }
    if (ret >= USE_DEFAULT)
        fill_response_struct_good(ftp, &response, data, ret);
    else
        fill_response_struct_bad(ftp, &response, data, ret);
    send_response_client(ftp, client, &response);
    return;
}
