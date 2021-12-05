/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** launch_login
*/

#include "../include/my.h"

void logg_client(t_client *client, t_info *info)
{
    client->info = info;
    client->uid = strdup(info->uid);
    client->is_logged = 1;
    if (client->name)
        free(client->name);
    client->name = strdup(info->name);
    client->info->status += 1;
}

void send_loggin_cli(t_control *control, t_client *client)
{
    t_client *elm = control->head_client;
    char str[1024];

    sprintf(str, "login %s %s", client->uid, client->name);
    for (; elm; elm = elm->next) {
        if (!elm->fd)
            continue;
        if (elm->fd == client->fd)
            continue;
        if (!elm->is_logged)
            continue;
        my_send(elm->fd, str);
    }
}

void launch_login(t_control *control, t_client *client, char *arg)
{
    t_info *info = NULL;
    char str[1024];
    int ret = 0;

    if (client->is_logged) {
        my_send(client->fd, "ERROR connected");
        return;
    }
    cut_quote(&arg);
    info = find_info(control->head_info, arg);
    if (!info) {
        info = create_info(arg, NULL);
        add_info_list(control, info);
    }
    logg_client(client, info);
    server_event_user_logged_in(info->uid);
    ret = sprintf(str, "%s %s", info->uid, arg);
    str[ret] = '\0';
    my_send(client->fd, str);
    send_loggin_cli(control, client);
}