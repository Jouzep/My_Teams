/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** user_utils
*/

#include "commun.h"
#include "server.h"

bool check_if_user_exist(server_t *ftp, response_t *response,
    char *uuid_to_find)
{
    for (int i = 0; i < ftp->save.n_user; i++) {
        if (strcmp(uuid_to_find, ftp->save.users[i].client_uuid) == 0) {
            return true;
        }
    }
    response->error = ERR_CLIENT_NO_FOUND;
    strcpy(response->other_uuid, uuid_to_find);
    return false;
}
