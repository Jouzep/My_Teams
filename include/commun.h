/*
** EPITECH PROJECT, 2023
** B-NWP-400-PAR-4-1-myteams-joseph.yu
** File description:
** commun
*/

#ifndef COMMUN_H_
    #include <time.h>
    #include <stdbool.h>
    #include <netinet/in.h>
    #define COMMUN_H_

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define BUFFER_SIZE 1024
    #define MAX_CLIENT 10
    #define UUID 37

enum err_cmd {
    NO = 0,
    YES = -1,
    UNKNOW = -2,
    ALREADY = -3,
    UNAUTHORIZED = -4,
    UNKNOW_CHANNEL = -5,
    UNKNOW_THREAD = -6,
    UNKNOW_COMMENT = -7,
};

enum use_id {
    USE_DEFAULT = 0,
    USE_TEAM,
    USE_CHANNEL,
    USE_THREAD,
};

enum cmd {
    LOGIN = 0,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBCRIBE,
    USE,
    CREATE,
    LIST,
    INFO,
    HELP,
};

enum err_code {
    NO_ERR = 0,
    USAGE,
    ERR_PORT,
    ERR_SOCKET,
    ERR_BIND,
    ERR_LISTEN,
    ERR_MALLOC,
    ERR_SELECT,
    ERR_ACCEPT,
    ERR_ARGS,
    ERR_SERV_SOCKET,
    ERR_SERV_BIND,
    ERR_SERV_LIST,
    ERR_SERV_MALLOC,
    ERR_SERV_LISTEN,
    ERR_CLIENT_SOCKET,
    ERR_CLIENT_BIND,
    ERR_CLIENT_LIST,
    ERR_CLIENT_MALLOC,
    ERR_CLIENT_LISTEN,
    ERR_CLIENT_CONNECT,
    ERR_CLIENT_NO_FOUND,
    ERR = 84
};

typedef struct socket_s {
    struct sockaddr_in addr;
    int socket;
    bool connected;
    char client_uuid[UUID];
    char client_name[MAX_NAME_LENGTH];
    int use_id;

    char team_uuid[UUID];
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];

    char channel_uuid[UUID];
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];

    char thread_uuid[UUID];
    char thread_title[MAX_NAME_LENGTH];
    char thread_body[MAX_DESCRIPTION_LENGTH];

} socket_t;

typedef struct comment_s {
    char comment_uuid[UUID];
    char comment_description[MAX_DESCRIPTION_LENGTH];
    char creator_uuid[UUID];
    time_t comment_timestamp;
} comment_t;

typedef struct thread_s {
    char thread_uuid[UUID];
    char thread_name[MAX_NAME_LENGTH];
    char thread_description[MAX_DESCRIPTION_LENGTH];
    char creator_uuid[UUID];
    time_t thread_timestamp;

    int n_comment;
    comment_t *comment;
} thread_t;

typedef struct channel_s {
    char channel_uuid[UUID];
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];
    char creator_uuid[UUID];

    int n_thread;
    thread_t *thread;
} channel_t;

typedef struct teams_s {
    char team_uuid[UUID];
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
    char creator_uuid[UUID];

    int n_channel;
    channel_t *channel;
} teams_t;

typedef struct messages_s {
    char uuid_client[UUID];
    char uuid_other_client[UUID];
    char body_message[MAX_BODY_LENGTH];
    time_t message_timestamp;
    bool state;
} messages_t;

typedef struct subscribed_s {
    char sub_uuid[UUID];
    char sub_name[MAX_NAME_LENGTH];
    char sub_description[MAX_DESCRIPTION_LENGTH];
} subscribed_t;

typedef struct users_s {
    char client_name[MAX_NAME_LENGTH];
    char client_uuid[UUID];
    bool connected;

    int n_team;
    subscribed_t *team;
} users_t;

typedef struct response_s {
    char client_uuid[UUID];
    char client_name[MAX_NAME_LENGTH];
    char other_uuid[UUID];
    int cmd_id;
    int error;
    int total_clients;
    users_t users[100];
    users_t user_informations;
    char message[MAX_BODY_LENGTH];
    bool state;
    int use_id;
    int total_messages_exchanged;
    messages_t *messages_exchanged;
    int total_team;
    subscribed_t *teams;

    char team_uuid[UUID];
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];

    char channel_uuid[UUID];
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];

    char thread_uuid[UUID];
    char thread_title[MAX_NAME_LENGTH];
    char thread_body[MAX_DESCRIPTION_LENGTH];
    time_t thread_timestamp;

    char comment_uuid[UUID];
    char comment_title[MAX_NAME_LENGTH];
    char comment_body[MAX_DESCRIPTION_LENGTH];
    time_t comment_timestamp;
} response_t;

typedef struct data_s {
    char client_uuid[UUID];
    char client_name[MAX_NAME_LENGTH];
    char cmd[1024];
    int cmd_id;
    bool connected;
    int use_id;

    char team_uuid[UUID];
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];

    char channel_uuid[UUID];
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];

    char thread_uuid[UUID];
    char thread_title[MAX_NAME_LENGTH];
    char thread_body[MAX_DESCRIPTION_LENGTH];
    time_t thread_timestamp;

    char comment_uuid[UUID];
    char comment_title[MAX_NAME_LENGTH];
    char comment_body[MAX_DESCRIPTION_LENGTH];
    time_t comment_timestamp;
} data_t;

void init_response(response_t *response);

#endif /* !COMMUN_H_ */
