/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** create_socket
*/

#include "client.h"

int create_socket(void)
{
    int new_socket = 0;

    new_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (new_socket < 0) {
        return ERR_SOCKET;
    }
    return new_socket;
}

int init_socket(socket_t *socket, char **argv)
{
    socket->socket = create_socket();
    socket->addr.sin_family = AF_INET;
    socket->addr.sin_port = htons(atoi(argv[2]));
    if (socket->socket == -1)
        return ERR_SOCKET;
    return NO_ERR;
}
