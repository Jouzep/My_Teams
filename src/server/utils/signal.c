/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** signal
*/

#include "server.h"
#include <signal.h>

server_t *ftp_save;

void handle_sigint(int sig)
{
    (void) sig;
    save_file(ftp_save);
    clear_myteams(ftp_save);
    exit(0);
}

void init_signal(server_t *ftp)
{
    ftp_save = ftp;
    signal(SIGINT, handle_sigint);
}
