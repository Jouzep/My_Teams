/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** messages
*/

#include "server.h"

static void get_number_messages_exchanged(server_t *ftp, data_t *data,
response_t *response)
{
    for (int i = 0; i < ftp->save.n_messages; i++) {
        if (strcmp(ftp->save.messages[i].uuid_client, ftp->tab_cmd[1]) == 0 &&
            strcmp(ftp->save.messages[i].uuid_other_client,
            data->client_uuid) == 0) {
            response->total_messages_exchanged++;
            continue;
        }
        if ((strcmp(ftp->save.messages[i].uuid_client,
            data->client_uuid) == 0) &&
            strcmp(ftp->save.messages[i].uuid_other_client,
            ftp->tab_cmd[1]) == 0) {
            response->total_messages_exchanged++;
        }
    }
}

static void fill_response_message(response_t *response, server_t *ftp, int i,
const int *j)
{
    strcpy(response->messages_exchanged[*j].uuid_client,
    ftp->save.messages[i].uuid_client);
    strcpy(response->messages_exchanged[*j].body_message,
    ftp->save.messages[i].body_message);
    response->messages_exchanged[*j].message_timestamp =
    ftp->save.messages[i].message_timestamp;
}

static void fill_response_message_other(response_t *response, server_t *ftp,
int i, const int *j)
{
    strcpy(response->messages_exchanged[*j].uuid_client,
    ftp->save.messages[i].uuid_client);
    strcpy(response->messages_exchanged[*j].body_message,
    ftp->save.messages[i].body_message);
    response->messages_exchanged[*j].message_timestamp =
            ftp->save.messages[i].message_timestamp;
}

static void get_messages_exchanged(server_t *ftp, data_t *data,
response_t *response)
{
    int j = 0;

    for (int i = 0; i < ftp->save.n_messages; i++) {
        if (strcmp(ftp->save.messages[i].uuid_client, ftp->tab_cmd[1]) == 0 &&
            strcmp(ftp->save.messages[i].uuid_other_client,
            data->client_uuid) == 0) {
            strcpy(response->messages_exchanged[j].uuid_client,
            ftp->save.messages[i].uuid_client);
            fill_response_message(response, ftp, i, &j);
            j++;
            continue;
        }
        if ((strcmp(ftp->save.messages[i].uuid_other_client,
            ftp->tab_cmd[1]) == 0) &&
            strcmp(ftp->save.messages[i].uuid_client, data->client_uuid) == 0) {
            fill_response_message_other(response, ftp, i, &j);
        }
        j++;
    }
}

void do_messages(server_t *ftp, data_t *data, int client)
{
    response_t response;

    init_response(&response);
    response.cmd_id = MESSAGES;
    if (get_tab_size(ftp->tab_cmd) != 2) {
        response.error = ERR_ARGS;
        return;
    }
    if (!check_if_user_exist(ftp, &response, ftp->tab_cmd[1])) {
        send_response_client(ftp, client, &response);
        return;
    }
    get_number_messages_exchanged(ftp, data, &response);
    response.messages_exchanged = malloc(sizeof(messages_t) *
            response.total_messages_exchanged);
    get_messages_exchanged(ftp, data, &response);
    response.error = false;
    send_response_client(ftp, client, &response);
}
