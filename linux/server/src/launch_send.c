/*
** EPITECH PROJECT, 2021
** server
** File description:
** launch_send
*/

#include "../include/my.h"

void send_mess_cli(t_control *control, t_mess *mess, char *uid, char *s)
{
    t_client *client = control->head_client;
    char mes[1024];
    char c = mess->c;
    time_t now = mess->time;
    char *str = mess->mess;

    sprintf(mes, "%csend%c%s%c%s", c, c, s, c, str);
    for (; client; client = client->next) {
        if (!client->fd || !client->is_logged)
            continue;
        if (!strcmp(uid, client->uid))
            my_send(client->fd, mes);
    }
}

void launch_send(t_control *control, t_client *client, char *arg)
{
    char c = arg[0];
    char **arr = cut_str_array(arg, c);
    t_info *info = NULL;
    t_mess *mess = NULL;
    time_t now;

    info = find_info_uid(control->head_info, arr[0]);
    if (!info) {
        my_send(client->fd, "ERROR");
        return;
    }
    time(&now);
    my_send(client->fd, "OK");
    mess = create_mess(client->uid, arr[1], now, c);
    add_mess_list(info, mess);
    send_mess_cli(control, mess, arr[0], client->uid);
    free_array(arr);
}