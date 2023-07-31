/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** login
*/

#include "server.h"

static void fill_response_struct(response_t *response, char *name, char *uuid)
{
    strcpy(response->client_name, name);
    strcpy(response->client_uuid, uuid);
    response->error = NO;
    response->cmd_id = LOGIN;
}

static void add_user(server_t *ftp, int client)
{
    char *uuid = gen_uuid();

    strcpy(ftp->save.users[ftp->save.n_user].client_name, ftp->tab_cmd[1]);
    strcpy(ftp->save.users[ftp->save.n_user].client_uuid, uuid);
    ftp->save.users[ftp->save.n_user].team = malloc(sizeof(subscribed_t) * 1);
    ftp->save.users[ftp->save.n_user].n_team = 0;
    strcpy(ftp->client[client].client_name, ftp->tab_cmd[1]);
    strcpy(ftp->client[client].client_uuid, uuid);
    ftp->client[client].connected = true;
    ftp->client[client].use_id = USE_DEFAULT;
    ftp->save.users =
        realloc(ftp->save.users, sizeof(users_t) * (ftp->save.n_user + 2));
    server_event_user_created(uuid,
        ftp->save.users[ftp->save.n_user].client_name);
    ftp->save.n_user++;
    free(uuid);
}

static void check_user(server_t *ftp, int client)
{
    bool exist = false;

    for (int i = 0; i != ftp->save.n_user; i++) {
        if (strcmp(ftp->tab_cmd[1], ftp->save.users[i].client_name) == 0) {
            exist = true;
            strcpy(ftp->client[client].client_name,
                ftp->save.users[i].client_name);
            strcpy(ftp->client[client].client_uuid,
                ftp->save.users[i].client_uuid);
            ftp->client[client].connected = true;
            break;
        }
    }
    if (exist == false)
        add_user(ftp, client);
}

void do_login(server_t *ftp, data_t *data, int client)
{
    response_t response;
    (void) data;

    init_response(&response);
    if (get_tab_size(ftp->tab_cmd) == 2)
        check_user(ftp, client);
    fill_response_struct(&response,
        ftp->client[client].client_name, ftp->client[client].client_uuid);
    response.total_messages_exchanged = 0;
    send_response_client(ftp, client, &response);
    send_login_events(ftp, &response, client);
    server_event_user_logged_in(response.client_uuid);
}
