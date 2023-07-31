/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** server_response
*/

#include "client.h"

void get_server_response(client_t *clientData, response_t *server_response)
{
    char data[sizeof(response_t)];
    char data1[sizeof(messages_t)];
    int a;

    a = recv(clientData->client.socket, data, sizeof(data), 0);

    if (a == 0) {
        close_connection(clientData);
    }

    memcpy(server_response, data, sizeof(data));
    server_response->messages_exchanged = malloc(sizeof(messages_t) *
            server_response->total_messages_exchanged);
    for (int i = 0; i < server_response->total_messages_exchanged; i++) {
        recv(clientData->client.socket, data1, sizeof(data1), 0);
        memcpy(&server_response->messages_exchanged[i], data1, sizeof(data1));
        memset(data1, 0, sizeof(messages_t));
    }
}

void get_team_response(client_t *clientData, response_t *server_response)
{
    char data[sizeof(subscribed_t)];

    server_response->teams = malloc(sizeof(subscribed_t) *
            server_response->total_team);
    for (int i = 0; i < server_response->total_team; i++) {
        recv(clientData->client.socket, data, sizeof(data), 0);
        memcpy(&server_response->teams[i], data, sizeof(data));
        memset(data, 0, sizeof(data));
    }
}

void server_response(client_t *clientData)
{
    response_t data;
    get_server_response(clientData, &data);
    get_team_response(clientData, &data);
    handling_command(clientData, &data);
}
