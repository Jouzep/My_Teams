/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create
*/

#include "server.h"

commands_t create[] = {
    {&create_team, USE_DEFAULT},
    {&create_channel, USE_TEAM},
    {&create_thread, USE_CHANNEL},
    {&create_comment, USE_THREAD},
};

void do_create(server_t *ftp, data_t *data, int client)
{
    int size = sizeof(create) / sizeof(commands_t);

    for (int i = 0; i != size; i++) {
        if (create[i].cmd_id == data->use_id) {
            create[i].func(ftp, data, client);
            break;
        }
    }
    return;
}
