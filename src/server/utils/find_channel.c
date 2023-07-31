/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** find_channel
*/

#include "server.h"

int find_channel_index_by_uuid(teams_t *team, char *uuid)
{
    for (int i = 0; i != team->n_channel; i++) {
        if (strcmp(uuid, team->channel[i].channel_uuid) == 0)
            return i;
    }
    return 0;
}
