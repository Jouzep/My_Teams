/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** manage_client_response
*/

#include "server.h"

void parse_client_response(server_t *ftp, int client, char *str)
{
    data_t data;
    char **tmp;

    memcpy(&data, str, sizeof(data));
    free_array(ftp->tab_cmd);
    tmp = str_word_array(data.cmd);
    ftp->tab_cmd = remove_empty_string(tmp);
    handling_command(ftp, &data, client);
}

void send_response_client(server_t *ftp, int client, response_t *response)
{
    char buffer[sizeof(response_t)];
    char buffer1[sizeof(messages_t)];
    char buffer2[sizeof(subscribed_t)];

    memcpy(buffer, response, sizeof(response_t));
    if (send(ftp->client[client].socket, buffer, sizeof(response_t), 0) < 0) {
        exit(0);
    }
    for (int i = 0; i < response->total_messages_exchanged; i++) {
        memcpy(buffer1, &response->messages_exchanged[i], sizeof(messages_t));
        send(ftp->client[client].socket, buffer1, sizeof(messages_t), 0);
        memset(buffer1, 0, sizeof(messages_t));
    }
    for (int i = 0; i < response->total_team; i++) {
        memcpy(buffer2, &response->teams[i], sizeof(subscribed_t));
        send(ftp->client[client].socket, buffer2, sizeof(subscribed_t), 0);
        memset(buffer2, 0, sizeof(subscribed_t));
    }
}
