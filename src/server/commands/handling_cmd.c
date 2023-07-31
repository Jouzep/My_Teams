/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** handling_cmd
*/

#include "server.h"

commands_t commands[] = {
    {&do_logout, LOGOUT},
    {&do_users, USERS},
    {&do_user, USER},
    {&do_send, SEND},
    {&do_messages, MESSAGES},
    {&do_subscribe, SUBSCRIBE},
    {&do_subscribed, SUBSCRIBED},
    {&do_unsubscribe, UNSUBCRIBE},
    {&do_use, USE},
    {&do_create, CREATE},
    {&do_list, LIST},
    {&do_info, INFO},
    {&do_login, LOGIN},
};

void handling_command(server_t *ftp, data_t *data, int client)
{
    int size = sizeof(commands) / sizeof(commands_t);

    for (int i = 0; i != size; i++) {
        if (commands[i].cmd_id == data->cmd_id) {
            commands[i].func(ftp, data, client);
            break;
        }
    }
}
