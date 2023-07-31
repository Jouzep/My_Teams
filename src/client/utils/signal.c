/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** signal
*/

#include <signal.h>
#include "client.h"

const client_t *clientData_save;

void handle_sigint(int sig)
{
    (void) sig;
    close_connection(clientData_save);
    exit(0);
}

void init_signal(client_t *clientData)
{
    clientData_save = clientData;
    signal(SIGINT, handle_sigint);
}
