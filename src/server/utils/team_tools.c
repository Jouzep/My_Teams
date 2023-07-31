/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** team_tools
*/

#include "server.h"

bool check_team_name(server_t *ftp, char *name)
{
    bool exist = false;

    for (int i = 0; i != ftp->save.n_teams; i++) {
        if (strcmp(name, ftp->save.teams[i].team_name) == 0)
            exist = true;
    }
    return exist;
}

bool check_team_uuid(server_t *ftp, char *uuid)
{
    bool exist = false;

    for (int i = 0; i != ftp->save.n_teams; i++) {
        if (strcmp(uuid, ftp->save.teams[i].team_uuid) == 0)
            exist = true;
    }
    return exist;
}

bool check_team_user(server_t *ftp, char *team_uuid, char *user_uuid)
{
    bool exist = false;
    int user_index = get_index_user_by_uuid(ftp, user_uuid);

    for (int i = 0; i != ftp->save.users[user_index].n_team; i++) {
        if (strcmp(ftp->save.users[user_index].
            team[i].sub_uuid, team_uuid) == 0)
            exist = true;
    }
    return exist;
}
