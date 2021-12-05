/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_help
*/

#include "../include/my.h"

void launch_help(t_client *client, char **arg)
{
    if (arg[1]) {
        client_error_unauthorized();
        return;
    }
    write(2, "you want HELP ... Good luck\n", 28);
}