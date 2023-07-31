/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** find_team
*/

#include "server.h"

int find_team_user_index_by_uuid
    (server_t *ftp, char *uuid, int user_index)
{
    for (int i = 0; i != ftp->save.users[user_index].n_team; i++)
        if (strcmp(ftp->save.users[user_index].team[i].sub_uuid, uuid) == 0)
            return i;
    return 0;
}

int find_team_index_by_uuid(server_t *ftp, char *uuid)
{
    for (int i = 0; i != ftp->save.n_teams; i++) {
        if (strcmp(ftp->save.teams[i].team_uuid, uuid) == 0)
            return i;
    }
    return 0;
}

bool check_if_in_team(users_t users, char *team_uuid)
{
    for (int a = 0; a != users.n_team; a++)
        if (strcmp(users.team[a].sub_uuid, team_uuid) == 0) {
            return true;
        }
    return false;
}

bool check_if_team_exist(server_t *ftp, char *team_uuid)
{
    for (int i = 0; i != ftp->save.n_teams; i++) {
        if (strcmp(ftp->save.teams[i].team_uuid, team_uuid) == 0)
            return true;
    }
    return false;
}
