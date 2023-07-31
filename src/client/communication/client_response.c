/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** parse_client_input
*/

#include "client.h"

static void fill_use(client_t *clientData, data_t *data)
{
    if (clientData->client.use_id >= USE_TEAM) {
        strcpy(data->team_name, clientData->client.team_name);
        strcpy(data->team_uuid, clientData->client.team_uuid);
        strcpy(data->team_description, clientData->client.team_description);
    }
    if (clientData->client.use_id >= USE_CHANNEL) {
        strcpy(data->channel_name, clientData->client.channel_name);
        strcpy(data->channel_uuid, clientData->client.channel_uuid);
        strcpy(data->channel_description, clientData->client.
        channel_description);
    }
    if (clientData->client.use_id >= USE_THREAD) {
        strcpy(data->thread_title, clientData->client.thread_title);
        strcpy(data->thread_uuid, clientData->client.thread_uuid);
        strcpy(data->thread_body, clientData->client.thread_body);
    }
}

void fill_response_for_server(client_t *clientData, data_t *data, int cmd_id)
{
    strcpy(data->cmd, clientData->buffer);
    data->cmd_id = cmd_id;
    if (clientData->client.client_name == NULL) {
        data->client_name[0] = '\0';
        data->client_uuid[0] = '\0';
    } else {
        strcpy(data->client_name, clientData->client.client_name);
        strcpy(data->client_uuid, clientData->client.client_uuid);
    }
    fill_use(clientData, data);
    data->use_id = clientData->client.use_id;
    data->connected = clientData->client.connected;
}

int find_cmd(client_t *clientData)
{
    char *cmd[] = {"/login", "/logout", "/users",
    "/user", "/send", "/messages", "/subscribe",
    "/subscribed", "/unsubscribe", "/use", "/create",
    "/list", "/info", "/help", NULL};
    int cmd_id[] = {LOGIN, LOGOUT, USERS, USER, SEND,
    MESSAGES, SUBSCRIBE, SUBSCRIBED, UNSUBCRIBE, USE,
    CREATE, LIST, INFO, HELP};

    if (clientData->cmd[0] == NULL)
        return -1;
    for (int i = 0; cmd[i] != NULL; i++)
        if (strcmp(cmd[i], clientData->cmd[0]) == 0)
            return cmd_id[i];
    return -1;
}

// PRINT ERROR
void check_cmd(client_t *clientData, int cmd_id)
{
    if (cmd_id == -1) {
        return;
    }
    if (clientData->client.connected == true)
        client_connected(clientData, cmd_id);
    else
        client_disconnected(clientData, cmd_id);
}

int parse_client_response(client_t *clientData)
{
    if (read_on_fd(clientData, STDIN_FILENO) == ERR)
        return ERR;
    if (clientData->cmd == NULL)
        return ERR;
    if (clientData->cmd[0] == NULL)
        return NO_ERR;
    check_cmd(clientData, find_cmd(clientData));
    return NO_ERR;
}
