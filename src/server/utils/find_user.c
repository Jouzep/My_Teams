/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** find_user
*/

#include "server.h"

int get_index_user_by_uuid(server_t *ftp, char *uuid)
{
    for (int i = 0; i != ftp->save.n_user; i++)
        if (strcmp(uuid, ftp->save.users[i].client_uuid) == 0)
            return i;
    return 0;
}

int get_index_user_by_name(server_t *ftp, char *name)
{
    for (int i = 0; i != ftp->save.n_user; i++)
        if (strcmp(name, ftp->save.users[i].client_name) == 0)
            return i;
    return 0;
}
