/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** create_client
*/

#include "../include/my.h"

void add_client_list(t_control *control, t_client *client)
{
    if (!(control->head_client))
        control->head_client = client;
    else {
        if (!(control->tail_client)) {
            control->head_client->next = client;
            client->prev = control->head_client;
        } else {
            control->tail_client->next = client;
            client->prev = control->tail_client;
        }
        control->tail_client = client;
    }
    control->nb_client += 1;
}

t_client *create_client(int fd)
{
    t_client *client = (t_client *)malloc(sizeof(t_client));

    client->fd = fd;
    client->next = NULL;
    client->prev = NULL;
    client->info = NULL;
    client->name = strdup("\0");
    client->is_logged = 0;
    client->uid = NULL;
    return (client);
}
