/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create_socket
*/

#include "server.h"

int init_socket(socket_t *socket, int port)
{
    socket->socket = create_socket();
    socket->addr.sin_family = AF_INET;
    socket->addr.sin_port = htons(port);
    socket->addr.sin_addr.s_addr = INADDR_ANY;
    if (socket->socket == ERR_SOCKET)
        return ERR_SOCKET;
    return NO_ERR;
}

int create_socket(void)
{
    int new_socket = 0;

    new_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (new_socket < 0) {
        return ERR_SOCKET;
    }
    return new_socket;
}

int bind_socket(socket_t *server)
{
    int ret = bind(server->socket, (struct sockaddr *)&server->addr,
    sizeof(server->addr));

    if (ret < 0)
        return ERR_BIND;
    return NO_ERR;
}

int listen_socket(socket_t *server)
{
    int ret = listen(server->socket, MAX_CLIENT);

    if (ret < 0)
        return ERR_LISTEN;
    return NO_ERR;
}
