/*
** EPITECH PROJECT, 2021
** client
** File description:
** recv_login
*/

#include "../include/my.h"

void recv_login(char **arg)
{
    client_event_logged_in(arg[1], arg[2]);
}