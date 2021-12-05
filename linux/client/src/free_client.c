/*
** EPITECH PROJECT, 2021
** client
** File description:
** free_client
*/

#include "../include/my.h"

void free_client(t_client *client)
{
    free(client->com_func);
    free(client->com_str);
    close(client->fd);
    if (client->str)
        free(client->str);
    if (client->uid)
        free(client->uid);
    if (client->name)
        free(client->name);
}