/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** send
*/

#include <time.h>
#include "server.h"

static void save_message(server_t *ftp, data_t *data)
{
    time_t timestamp = time(NULL);

    strcpy(ftp->save.messages[ftp->save.n_messages].
    uuid_client, data->client_uuid);
    strcpy(ftp->save.messages[ftp->save.n_messages].
    uuid_other_client, ftp->tab_cmd[1]);
    strcpy(ftp->save.messages[ftp->save.n_messages].
    body_message, ftp->tab_cmd[2]);
    ftp->save.messages[ftp->save.n_messages].
    message_timestamp = timestamp;
    ftp->save.n_messages++;
}

static void send_message(server_t *ftp, data_t *data)
{
    response_t response;

    init_response(&response);
    for (int i = 0; i < ftp->save.n_user; i++) {
        if (strcmp(ftp->client[i].client_uuid, ftp->tab_cmd[1]) == 0) {
            strcpy(response.client_uuid, data->client_uuid);
            strcpy(response.message, ftp->tab_cmd[2]);
            response.cmd_id = SEND;
            response.state = true;
            send_response_client(ftp, i, &response);
        }
    }
}

void do_send(server_t *ftp, data_t *data, int client)
{
    response_t response;
    (void) data;

    init_response(&response);
    response.cmd_id = SEND;
    if (get_tab_size(ftp->tab_cmd) != 3)
        return;
    if (!check_if_user_exist(ftp, &response, ftp->tab_cmd[1])) {
        send_response_client(ftp, client, &response);
        return;
    }
    response.state = false;
    strcpy(response.client_uuid, data->client_uuid);
    strcpy(response.client_name, data->client_name);
    save_message(ftp, data);
    server_event_private_message_sended(
        ftp->client[client].client_uuid, ftp->tab_cmd[1], ftp->tab_cmd[2]);
    send_message(ftp, data);
    send_response_client(ftp, client, &response);
}
