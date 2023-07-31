/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** gen_uuid
*/

#include <uuid/uuid.h>
#include "server.h"

char *gen_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(37);

    uuid_generate_random(binuuid);
    uuid_unparse_lower(binuuid, uuid);
    return uuid;
}
