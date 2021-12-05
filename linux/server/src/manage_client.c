/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** manage_client
*/

#include "../include/my.h"

char *get_input(int fd)
{
    char *str = (char *)malloc(sizeof(char) * 200);
    int ret = read(fd, str, 199);

    if (ret <= 0) {
        free(str);
        return (NULL);
    }
    str[ret] = '\0';
    if (ret - 1 >= 0 && str[ret - 1] == '\n')
        str[ret - 1] = '\0';
    for (int j = 0; str[j]; j++) {
        if (str[j] == '\r')
            str[j] = '\0';
    }
    return (str);
}

void fill_command(char *input, char **command, char **arg)
{
    int i = 0;

    for (; input[i] && input[i] != ' '; i++);
    (*arg) = ((input[i]) ? &(input[i + 1]) : NULL);
    input[i] = '\0';
    (*command) = input;
}

void manage_client(t_client *client, t_control *control)
{
    char *command = NULL;
    char *arg = NULL;
    char *input = get_input(client->fd);

    fill_command(input, &command, &arg);
    launch_command(control, client, command, arg);
    if (input)
        free(input);
}