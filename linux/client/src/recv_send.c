/*
** EPITECH PROJECT, 2021
** client
** File description:
** recv_send
*/

#include "../include/my.h"

void recv_send(char **arg)
{
    int (*ptr)(const char *, const char *);

    ptr = client_event_private_message_received;
    (*ptr)(arg[1], arg[2]);
}