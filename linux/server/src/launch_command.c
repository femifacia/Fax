/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** launch_command
*/

#include "../include/my.h"

void launch_command(t_control *control, t_client *client, char *com, char *arg)
{
    int func = -1;

    if (!com)
        return;
    for (int i = 0; control->com_str[i]; i++) {
        if (!strcmp(control->com_str[i], com)) {
            func = i;
            break;
        }
    }
    if (func < 0)
        return ;
    (*(control->com_func[func]))(control, client, arg);
}