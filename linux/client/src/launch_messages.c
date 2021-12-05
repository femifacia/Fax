/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_messages
*/

#include "../include/my.h"

bool check_mess_arg(t_client *client, char **arg)
{
    int len = 0;

    if (!client->is_logged) {
        client_error_unauthorized();
        return (1);
    }
    len = my_array_len(arg);
    if (len != 2) {
        error_arg();
        return (1);
    }
    return (0);
}

void print_mess_line(char *line)
{
    char **arg = cut_str_array(line, line[0]);
    int (*ptr)(const char *, time_t, const char *) = NULL;
    int len = my_array_len(arg);

    if (len != 3) {
        free_array(arg);
        return;
    }
    ptr = client_private_message_print_messages;
    (*ptr)(arg[0], atol(arg[1]), arg[2]);
    free_array(arg);
}

void launch_messages(t_client *client, char **arg)
{
    char str[1024];
    int ret = 0;
    char ans[2048];
    char **line = NULL;

    if (check_mess_arg(client, arg))
        return;
    sprintf(str, "/messages %s", arg[1]);
    my_send(client->fd, str);
    ret = read(client->fd, ans, 2048);
    ans[ret] = '\0';
    if (!strcmp(ans, "ERROR")) {
        client_error_unknown_user(arg[1]);
        return;
    }
    line = cut_str_array(ans, '\n');
    for (int i = 0; line[i]; i++)
        print_mess_line(line[i]);
    free_array(line);
}