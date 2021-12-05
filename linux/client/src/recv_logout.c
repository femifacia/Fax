/*
** EPITECH PROJECT, 2021
** client
** File description:
** recv_logout
*/

#include "../include/my.h"

void recv_logout(char **arg)
{
    client_event_logged_out(arg[1], arg[2]);
}