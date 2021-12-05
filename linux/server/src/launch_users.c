/*
** EPITECH PROJECT, 2021
** server
** File description:
** launch_users
*/

#include "../include/my.h"

void launch_users(t_control *control, t_client *client, char *arg)
{
    char str[1024];
    int status = 0;
    char *str1 = strdup("\0");
    char *str2 = "";
    int i = 0;

    for (t_info *info = control->head_info; info; info = info->next) {
        status = ((info->status > 0) ? 1 : 0);
        sprintf(str, "%s %s %d\n", info->uid, info->name, status);
        str2 = str1;
        str1 = my_strconcat(str, str1);
        free(str2);
    }
    my_send(client->fd, str1);
    free(str1);
}