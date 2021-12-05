/*
** EPITECH PROJECT, 2021
** server
** File description:
** launch_messages
*/

#include "../include/my.h"

void send_mess_resp(t_client *client, char *str, bool is_unk)
{
    if (is_unk)
        my_send(client->fd, "ERROR");
    else
        my_send(client->fd, str);
}

void fill_mess_var(int *is_unk, char **str3, char *c, t_mess *mess)
{
    *is_unk = 0;
    *str3 = mess->mess;
    *c = mess->c;
}

void launch_messages(t_control *control, t_client *cli, char *arg)
{
    char str[2048];
    char *str1 = strdup("\0");
    char *str2 = "";
    char *str3 = NULL;
    int is_unknown = 1;
    t_mess *mess = ((cli->info) ? cli->info->head_mess : NULL);
    char c = 0;

    for (; mess; mess = mess->next) {
        if (!strcmp(mess->from_uid, arg)) {
            fill_mess_var(&is_unknown, &str3, &c, mess);
            sprintf(str, "%c%s%c%ld%c%s\n", c, arg, c, mess->time, c, str3);
            str2 = str1;
            str1 = my_strconcat(str, str1);
            free(str2);
        }
    }
    send_mess_resp(cli, str1, is_unknown);
    free(str1);
}