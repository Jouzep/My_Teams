/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** save_team
*/

#include "server.h"

static void save_message(server_t *ftp, FILE *file)
{
    fwrite(&ftp->save.n_messages, sizeof(int), 1, file);
    for (int i = 0; i != ftp->save.n_messages; i++)
        fwrite(&ftp->save.messages[i], sizeof(messages_t), 1 ,file);
}

static void save_subscribed_team(server_t *ftp, FILE *file, int i)
{
    for (int a = 0; a != ftp->save.users[i].n_team; a++)
        fwrite(&ftp->save.users[i].team[a], sizeof(subscribed_t), 1, file);
}

static void save_user(server_t *ftp, FILE *file)
{
    fwrite(&ftp->save.n_user, sizeof(int), 1, file);
    for (int i = 0; i != ftp->save.n_user; i++) {
        fwrite(&ftp->save.users[i], sizeof(users_t), 1 ,file);
        save_subscribed_team(ftp, file, i);
    }
}

void save_file(server_t *ftp)
{
    FILE *file = fopen("save.dat", "wb");

    if (file == NULL)
        printf("Failed to save\n");
    else {
        save_user(ftp, file);
        save_message(ftp, file);
        save_team(ftp, file);
        fclose(file);
    }
}
