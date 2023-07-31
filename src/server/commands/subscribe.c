/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** subscribe
*/

#include "server.h"

static void fill_response_struct_unknow(server_t *ftp, response_t *response)
{
    strcpy(response->team_uuid, ftp->tab_cmd[1]);
    response->error = UNKNOW;
    response->cmd_id = SUBSCRIBE;
    response->total_messages_exchanged = 0;
    printf("teams dond exist\n");
}

static void fill_response_struct_bad_arg(server_t *ftp, response_t *response)
{
    (void) ftp;
    response->error = YES;
    response->cmd_id = SUBSCRIBE;
    response->total_messages_exchanged = 0;
    printf("invalid args\n");
}

void do_subscribe(server_t *ftp, data_t *data, int client)
{
    int size = get_tab_size(ftp->tab_cmd);
    response_t response;

    response.cmd_id = SUBSCRIBE;
    response.total_team = 0;
    if (size != 2)
        fill_response_struct_bad_arg(ftp, &response);
    else if (check_team_uuid(ftp, ftp->tab_cmd[1])) {
        check_subscription(ftp, &response, data, client);
    } else
        fill_response_struct_unknow(ftp, &response);
    send_response_client(ftp, client, &response);
    return;
}
