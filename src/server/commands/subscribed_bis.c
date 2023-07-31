/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribed_bis
*/

#include "server.h"

void fill_reponse_struct_good_arg_teams_bis(server_t *ftp,
    response_t *response, char *team_uuid)
{
    for (int i = 0; i != ftp->save.n_user; i++) {
        if (check_if_in_team(ftp->save.users[i], team_uuid) == true) {
            response->total_clients++;
            strcpy(response->users[i].client_name,
                ftp->save.users[i].client_name);
            strcpy(response->users[i].client_uuid,
                ftp->save.users[i].client_uuid);
            response->users[i].connected = ftp->save.users[i].connected;
        }
    }
}
