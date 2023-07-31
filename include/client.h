/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
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
    #include "commun.h"
    #include "logging_client.h"
    // #define ERR,  84
    // #define NO_ERR,  0
    // #define USAGE,  2
    // #define ERR_PORT, 3
    // #define ERR_SOCKET, 4
    // #define ERR_BIND, 5
    // #define ERR_LISTEN, 6
    // #define ERR_MALLOC, 7
    // #define ERR_SELECT, 8
    // #define ERR_ACCEPT, 8
    // #define ERR_ARGS, 9

    // #define ERR_SERV_SOCKET, 11
    // #define ERR_SERV_BIND, 12
    // #define ERR_SERV_LIST, 13
    // #define ERR_SERV_MALLOC, 14
    // #define ERR_SERV_LISTEN, 15

    // #define ERR_CLIENT_SOCKET, 21
    // #define ERR_CLIENT_BIND, 22
    // #define ERR_CLIENT_LIST, 23
    // #define ERR_CLIENT_MALLOC, 24
    // #define ERR_CLIENT_LISTEN, 25

// typedef struct socket_s {
//     struct sockaddr_in addr;
//     int socket;
// } socket_t;

typedef struct client_s {
    socket_t client;
    int addrlen;
    fd_set r_set;
    fd_set w_set;
    fd_set e_set;
    char buffer[BUFFER_SIZE];
    char **cmd;
} client_t;

typedef struct commands_s {
    void (*func)(client_t * clientData,
    response_t * data);
    int cmd_id;
} commands_t;

int display_usage(char *str);
int check_arg(char **av, int ac);

int init_socket(socket_t *socket, char **argv);
int my_teams(char **arg);
int do_select(client_t *clientData);
int connect_to_server(client_t *clientData, char **argv);
void set_fdset(client_t *clientData);
void clear_end_of_line(char *buffer);
int read_on_fd(client_t *clientData, int fd);

void print_create_event(response_t *data);

int get_tab_size(char **str);
void send_response_to_server(client_t *clienData, int cmd_id);
void fill_response_for_server(client_t *clientData, data_t *data, int cmd_id);
int count_word(char *str);
void free_array(char **tab);
char **str_word_array(char *str);
char **str_word_array_quote(char *str);
bool check_input(char **str);
int parse_client_response(client_t *clienData);
int parse_server_response(client_t *clientData);
void server_response(client_t *clientData);

void client_connected(client_t *clientData, int cmd_id);
void client_disconnected(client_t *clientData, int cmd_id);

// CMD
void handling_command(client_t *ftp, response_t *data);
// FUNC
void do_login(client_t *, response_t *);
void do_logout(client_t *, response_t *);
void do_users(client_t *, response_t *);
void do_user(client_t *, response_t *);
void do_send(client_t *, response_t *);
void do_messages(client_t *, response_t *);
void do_subscribe(client_t *, response_t *);
void do_subscribed(client_t *, response_t *);
void do_unsubscribe(client_t *, response_t *);
void do_use(client_t *, response_t *);
void do_create(client_t *, response_t *);
void do_list(client_t *, response_t *);
void do_info(client_t *, response_t *);
void do_help(void);

void init_signal(client_t*);
void close_connection(const client_t *clientData);

#endif /* !CLIENT_H_ */
