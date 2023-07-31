/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** Client main
*/

#include "client.h"
#include "logging_server.h"
#include "logging_client.h"
#include <dlfcn.h>

void display_error(int code)
{
    int error[] = {
    USAGE, ERR_PORT, ERR_SOCKET, ERR_BIND, ERR_LISTEN,
    ERR_MALLOC, ERR_SELECT, ERR_ACCEPT, ERR_ARGS,
    ERR_SERV_SOCKET, ERR_SERV_BIND, ERR_SERV_LIST,
    ERR_SERV_MALLOC, ERR_SERV_LISTEN, ERR_CLIENT_SOCKET,
    ERR_CLIENT_BIND, ERR_CLIENT_LIST, ERR_CLIENT_MALLOC,
    ERR_CLIENT_LISTEN, ERR_CLIENT_CONNECT};
    const char *message[] = {
    "", "Port", "Socket", "Bind", "Listen", "Malloc Erroc",
    "Select", "Accept", "Arguments", "Server Socket", "Server Bind",
    "Server List", "Server Malloc", "Server Listen", "Client Socket",
    "Client Bind", "Client List", "Client Malloc", "Client Listen",
    "Client Connect to Server"};

    for (int i = 0; i != sizeof(error) / sizeof(int); i++)
        if (code == error[i]) {
            printf("%s Error\n", message[i]);
            break;
        }
}

int main(int ac, char **av)
{
    int ret = 0;

    if (ac != 3 && ac != 2)
        return ERR;
    ret = check_arg(av, ac);
    display_error(ret);
    return ret;
}
