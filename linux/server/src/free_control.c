/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** free_control
*/

#include "../include/my.h"

void free_client_list(t_client *client)
{
    t_client *client_next = ((client) ? client->next : NULL);

    while (client) {
        if (client->fd != 0)
            close(client->fd);
        if (client->name)
            free(client->name);
        if (client->uid)
            free(client->uid);
        free(client);
        client = client_next;
        client_next = ((client) ? client->next : NULL);
    }
}

void free_mess_list(t_mess *elm)
{
    t_mess *elm_next = ((elm) ? elm->next : NULL);

    while (elm) {
        if (elm->from_uid)
            free(elm->from_uid);
        if (elm->mess)
            free(elm->mess);
        free(elm);
        elm = elm_next;
        elm_next = ((elm) ? elm->next : NULL);
    }
}

void free_info_list(t_info *info)
{
    t_info *info_next = ((info) ? info->next : NULL);

    while (info) {
        if (info->name)
            free(info->name);
        if (info->uid)
            free(info->uid);
        free_mess_list(info->head_mess);
        free(info);
        info = info_next;
        info_next = ((info) ? info->next : NULL);
    }
}

void free_control(t_control *control)
{
    free_client_list(control->head_client);
    free_info_list(control->head_info);
    if (control->highest_socket)
        close(control->highest_socket);
    free(control->com_func);
    free(control->com_str);
    free(control);
}
