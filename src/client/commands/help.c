/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** help
*/

#include "client.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

int size_file(char *path)
{
    int ret;
    struct stat sb;

    ret = stat(path, &sb);
    if (ret == -1) {
        return -1;
    }
    return sb.st_size;
}

char *get_file_content(char *str)
{
    char *map = malloc(sizeof(char) * (size_file(str) + 1));
    int ret = 0;

    if (map == NULL) {
        return NULL;
    }
    if ((ret = open(str, O_RDONLY, O_WRONLY)) == -1) {
        return NULL;
    }
    if ((ret = read(ret, map, size_file(str))) == 0) {
        return NULL;
    }
    map[ret] = '\0';
    return map;
}

void do_help(void)
{
    char *buf = get_file_content ("assets/help_message/help.txt");
    printf("%s", buf);
    return;
}
