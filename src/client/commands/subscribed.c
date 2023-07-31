/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribed
*/

#include "client.h"

void do_subscribed(client_t *clientData, response_t *data)
{
    int size = get_tab_size(clientData->cmd);

    if (size == 1) {
        for (int i = 0; i != data->total_team; i++) {
            client_print_team(data->teams[i].sub_uuid,
                data->teams[i].sub_name, data->teams[i].sub_description);
        }
    } else {
        for (int i = 0; i != data->total_clients; i++)
            client_print_users(data->users[i].client_uuid,
                data->users[i].client_name, data->users[i].connected);
    }
    return;
}
