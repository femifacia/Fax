/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_command
*/

#include "../include/my.h"

void launch_command(t_client *client, char **arg)
{
    int func = -1;

    if (!arg)
        return;
    if (!arg[0])
        return;
    for (int i = 0; client->com_str[i]; i++) {
        if (!strcmp(client->com_str[i], arg[0])) {
            func = i;
            break;
        }
    }
    if (func < 0 && !client->is_logged) {
        client_error_unauthorized();
        return ;
    } else if (func < 0 && client->is_logged) {
        function_unknown();
        return;
    }
    (*(client->com_func[func]))(client, arg);
}