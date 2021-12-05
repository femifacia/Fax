/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_send
*/

#include "../include/my.h"

bool check_send_error(t_client *client, char **arg, int len)
{
    if (!client->is_logged) {
        client_error_unauthorized();
        return (1);
    }
    if (len != 3) {
        error_arg();
        return (1);
    }
    if (!strcmp(client->uid, arg[1])) {
        client_error_unauthorized();
        return (1);
    }
    for (int i = 0; arg[i]; i++) {
        if (!strcmp(arg[i], "\0")) {
            error_arg();
            return (1);
        }
    }
    return (0);
}

void launch_send(t_client *client, char **arg)
{
    char str[1024];
    char *del = "%@+;";
    char c = 0;
    char ans[1024];
    int ret = 0;
    int len = my_array_len(arg);

    if (check_send_error(client, arg, len))
        return;
    c = get_del(del, arg[2]);
    sprintf(str, "%s %c%s%c%s", arg[0], c, arg[1], c, arg[2]);
    my_send(client->fd, str);
    ret = read(client->fd, ans, 1024);
    ans[ret] = '\0';
    if (!strcmp(ans, "ERROR"))
        client_error_unknown_user(arg[1]);
}