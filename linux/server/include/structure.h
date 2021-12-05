/*
** EPITECH PROJECT, 2019
** structure.h
** File description:
** the header file that countains structure and typedef
*/

#ifndef CHECK_STRUCT
#define CHECK_STRUCT 5

#include "libra.h"

typedef struct t_mess {
    char c;
    char *mess;
    char *from_uid;
    time_t time;
    struct t_mess *next;
    struct t_mess *prev;
}t_mess;
typedef struct t_info {
    int status;
    char *name;
    char *uid;
    uuid_t binuuid;
    t_mess *head_mess;
    t_mess *tail_mess;
    struct t_info *next;
    struct t_info *prev;
}t_info;

typedef struct t_client {
    int fd;
    char *uid;
    char *name;
    int is_logged;
    t_info *info;
    struct t_client *next;
    struct t_client *prev;
}t_client;

typedef struct t_control {
    int port;
    int highest_socket;
    struct sockaddr_in addr_in;
    int addr_len;
    int nb_client;
    t_info *head_info;
    t_info *tail_info;
    t_client *head_client;
    t_client *tail_client;
    fd_set fds;
    char **com_str;
    void (**com_func)(struct t_control *, t_client *, char *arg);
}t_control;
typedef void (*func_ptr)(t_control *, t_client *, char *arg);
#endif
