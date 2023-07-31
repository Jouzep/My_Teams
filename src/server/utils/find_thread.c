/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** find_thread
*/

#include "server.h"

int find_thread_index_by_uuid(channel_t *channel, char *uuid)
{
    for (int i = 0; i != channel->n_thread; i++) {
        if (strcmp(channel->thread[i].thread_uuid, uuid) == 0)
            return i;
    }
    return 0;
}
