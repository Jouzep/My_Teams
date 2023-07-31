/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** send_response
*/

#include "client.h"

void send_response_to_server(client_t *clienData, int cmd_id)
{
    data_t data;
    char buffer[sizeof(data_t)];

    fill_response_for_server(clienData, &data, cmd_id);
    memcpy(buffer, &data, sizeof(data_t));
    if (send(clienData->client.socket, buffer, sizeof(buffer), 0) < 0) {
        exit(0);
    }
}

static void send_response(client_t *clientData, int cmd_id)
{
    if (cmd_id != -1)
        send_response_to_server(clientData, cmd_id);
}

void client_connected(client_t *clientData, int cmd_id)
{
    if (cmd_id == LOGIN)
        printf("Already Logged in\n");
    else if (cmd_id == HELP)
        do_help();
    else
        send_response(clientData, cmd_id);
}

void client_disconnected(client_t *clientData, int cmd_id)
{
    if (cmd_id == HELP)
        do_help();
    else if (cmd_id == LOGIN && get_tab_size(clientData->cmd) == 2)
        send_response_to_server(clientData, cmd_id);
    else
        printf("Use /Login 'user_name'\n");
}
