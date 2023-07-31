/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include "commun.h"
    #include "logging_server.h"


    #define ERR  84
    #define NO_ERR  0
    #define USAGE  2
    #define ERR_PORT 3
    #define ERR_SOCKET 4
    #define ERR_BIND 5
    #define ERR_LISTEN 6
    #define ERR_MALLOC 7
    #define ERR_SELECT 8
    #define ERR_ACCEPT 8

    #define ERR_SERV_SOCKET 11
    #define ERR_SERV_BIND 12
    #define ERR_SERV_LIST 13
    #define ERR_SERV_MALLOC 14
    #define ERR_SERV_LISTEN 15

    #define ERR_CLIENT_SOCKET 21
    #define ERR_CLIENT_BIND 22
    #define ERR_CLIENT_LIST 23
    #define ERR_CLIENT_MALLOC 24
    #define ERR_CLIENT_LISTEN 25

    #define RECEIVE
    #define SENDER

typedef struct save_s {
    int n_user;
    users_t *users;

    int n_messages;
    messages_t *messages;

    int n_teams;
    teams_t *teams;
} save_t;

typedef struct server_s {
    fd_set r_set;
    fd_set w_set;
    fd_set e_set;
    socket_t *client;
    socket_t server;
    socket_t tmp;
    int addrlen;
    char **tab_cmd;
    save_t save;
} server_t;

typedef struct commands_s {
    void (*func)(server_t * ftp,
    data_t * data, int client);
    int cmd_id;
} commands_t;

typedef struct use_s {
    int (*func)(server_t * ftp,
    data_t * data, int client);
    int cmd_id;
} use_t;

int display_usage(char *str);
int check_arg(char *str);

int init_server(server_t *ftp, size_t port);
int init_socket(socket_t *socket, int port);
int bind_socket(socket_t *server);
int listen_socket(socket_t *server);
int create_socket(void);

int my_teams(int port);

void set_fdset(server_t *ftp);
int do_select(server_t *ftp);

int add_client(server_t *ftp);
void disconnect_client(server_t *ftp, int client);
void read_client(server_t *ftp);
void close_client(server_t *ftp, int client);

int manage_select(server_t *ftp);
void free_array(char **tab);
char **str_word_array(char *str);
void parse_client_response(server_t *ftp, int client, char *str);
void send_response_client(server_t *ftp, int client, response_t *response);
// CMD

void handling_command(server_t *ftp, data_t *data, int client);
// FUNC
void do_login(server_t *ftp, data_t *data, int client);
void do_logout(server_t *ftp, data_t *data, int client);
void do_users(server_t *ftp, data_t *data, int client);
void do_user(server_t *ftp, data_t *data, int client);
void do_send(server_t *ftp, data_t *data, int client);
void do_messages(server_t *ftp, data_t *data, int client);
void do_subscribe(server_t *ftp, data_t *data, int client);
void do_subscribed(server_t *ftp, data_t *data, int client);
void do_unsubscribe(server_t *ftp, data_t *data, int client);
void do_use(server_t *ftp, data_t *data, int client);

//CREATE
void do_create(server_t *ftp, data_t *data, int client);
void create_team(server_t *ftp, data_t *data, int client);
void create_channel(server_t *ftp, data_t *data, int client);
void create_thread(server_t *ftp, data_t *data, int client);
void create_comment(server_t *ftp, data_t *data, int client);
void send_team(server_t *ftp, response_t *response, int client);
void send_channel(server_t *ftp, response_t *response, int client);
void send_thread(server_t *ftp, response_t *response, int client);

//SUBSCRIBE

bool already_subscribe(server_t *ftp, int user_index, char *team_uuid);
void subscribe_user(server_t *ftp, data_t *data, int client);
void check_subscription(server_t *ftp,
    response_t *response, data_t *data, int client);

//SUBSCRIBED
void fill_reponse_struct_good_arg_teams_bis(server_t *ftp, response_t
*response, char *team_uuid);

void do_list(server_t *ftp, data_t *data, int client);
void do_info(server_t *ftp, data_t *data, int client);
void do_help(server_t *ftp, data_t *data, int client);

//USE
int find_comment(server_t *ftp, data_t *data, int client);
int find_channel(server_t *ftp, data_t *data, int client);
int find_thread(server_t *ftp, data_t *data, int client);
int find_team(server_t *ftp, data_t *data, int client);
bool check_if_subscribed(server_t *ftp, data_t *data, int client);
void fill_use(server_t *ftp, response_t *response, int size);

// File
FILE *open_file(char *pathName, char *options);
bool file_exist(char *pathName);
bool create_file(char *nameFile);
void save_folder(void);
void restaure_server(server_t *server);

char *gen_uuid(void);
void save_file(server_t *ftp);

void init_signal(server_t *ftp);

void clear_myteams(server_t *ftp);

int get_tab_size(char **str);
char **remove_empty_string(char **tab);

void default_user(server_t *server);
void default_message(server_t *server);
void default_team(server_t *server);
void save_team(server_t *ftp, FILE *file);
void restore_team(server_t *server, FILE *file);

// TOOLS
int get_index_user_by_uuid(server_t *ftp, char *uuid);
int get_index_user_by_name(server_t *ftp, char *name);
bool check_team(server_t *ftp, char *uuid);
bool check_team_user(server_t *ftp, char *team_uuid, char *user_uuid);
bool check_if_team_exist(server_t *ftp, char *team_uuid);
int find_team_user_index_by_uuid(server_t *ftp, char *uuid, int user_index);
int find_team_index_by_uuid(server_t *ftp, char *uuid);
bool check_if_in_team(users_t users, char *team_uuid);
bool check_team_name(server_t *ftp, char *name);
bool check_if_user_exist(server_t *ftp, response_t *response,
char *uuid_to_find);
void fill_newchannel(char **cmd, channel_t *channel, data_t *data);
int find_team_index_by_uuid(server_t *ftp, char *uuid);
bool check_if_team_exist(server_t *ftp, char *team_uuid);
bool check_team_uuid(server_t *ftp, char *uuid);
bool check_team_uuid(server_t *, char *);
void malloc_comment(thread_t *thread);
void malloc_thread(channel_t *channel);
void malloc_channel(teams_t *team);
void malloc_new_team(server_t *ftp);
int find_channel_index_by_uuid(teams_t *team, char *uuid);
int find_thread_index_by_uuid(channel_t *channel, char *uuid);
void send_login_events(server_t *ftp, response_t *response, int client);
#endif /* !SERVER_H_ */
