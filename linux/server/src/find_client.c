/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_client
*/

#include "../include/my.h"

t_client *find_client(t_client *client, char *name)
{
    for (;client; client = client->next) {
        if (!client->name)
            continue;
        if (!strcmp(client->name, name))
            return (client);
    }
    return (NULL);
}