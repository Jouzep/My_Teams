/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** use_find
*/

#include "server.h"

int find_channel(server_t *, data_t *, int)
{
    return 1;
}

int find_thread(server_t *, data_t *, int)
{
    return 1;
}

int find_comment(server_t *, data_t *, int)
{
    return 1;
}

int find_team(server_t *ftp, data_t *data, int client)
{
    char *team_uuid = ftp->tab_cmd[1];
    int ret = -1;
    for (int i = 0; i != ftp->save.n_teams; i++)
        if (strcmp(ftp->save.teams[i].team_uuid, team_uuid) == 0)
            ret = USE_TEAM;
    if (check_if_subscribed(ftp, data, client) == false)
        ret = UNAUTHORIZED;
    if (check_if_team_exist(ftp, ftp->tab_cmd[1]) == false)
        ret = UNKNOW;
    return ret;
}
