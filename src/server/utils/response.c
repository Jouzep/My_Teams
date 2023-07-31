/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** response
*/

#include <string.h>
#include "commun.h"

void init_response(response_t *response)
{
    strcpy(response->client_name, "");
    strcpy(response->client_uuid, "");
    strcpy(response->other_uuid, "");
    response->cmd_id = -1;
    response->error = false;
    response->state = false;
    response->use_id = -1;
    response->total_messages_exchanged = 0;
    response->total_team = 0;
}
