/*
** EPITECH PROJECT, 2019
** structure.h
** File description:
** the header file that countains structure and typedef
*/

#ifndef CHECK_STRUCT
#define CHECK_STRUCT 5

#include "libra.h"

typedef struct t_client {
    bool is_logged;
    bool is_connected;
    int fd;
    int delim;
    char *str;
    char *name;
    char *uid;
    struct sockaddr_in serv_addr;
    char **com_str;
    void (**com_func)(struct t_client *, char **arg);
    fd_set set;
}t_client;

typedef void (*func_ptr)(t_client *, char **arg);

#endif
