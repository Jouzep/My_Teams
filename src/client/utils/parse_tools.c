/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** parse_tools
*/

#include "client.h"

void clear_end_of_line(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
}

int fill_cmd(client_t *clientData)
{
    char tmp[BUFFER_SIZE + 1];

    strcpy(tmp, clientData->buffer);
    free_array(clientData->cmd);
    clientData->cmd = str_word_array_quote(clientData->buffer);
    if (!check_input(str_word_array(tmp)))
        return ERR;
    return NO_ERR;
}

int read_on_fd(client_t *clientData, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int a = 0;

    a = read(fd, buffer, BUFFER_SIZE);
    buffer[a] = '\0';
    clear_end_of_line(buffer);
    strcpy(clientData->buffer, buffer);
    if (fill_cmd(clientData) == ERR)
        return ERR;
    strcpy(clientData->buffer, buffer);
    return NO_ERR;
}
