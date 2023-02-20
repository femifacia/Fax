/*
** EPITECH PROJECT, 2021
** client
** File description:
** launch_client
*/

#include "../include/my.h"

void print_answer(int fd)
{
    char str[1024];
    int ret = 0;

    ret = read(fd, str, 1023);
    if (ret == 0)
        return;
    if (ret == -1)
        exit(84);
    str[ret - 1] = '\0';
    printf("%s\n", str);
}

char *get_input(t_client *client)
{
    size_t size = 0;
    char *str = NULL;
    int ret = 0;

    client->str = NULL;
    ret = getline(&(client->str), &size, stdin);
    if (ret < 0)
        return (NULL);
    str = client->str;
    str[ret - 1] = '\0';
    return (str);
}

void fill_command(t_client *client, char *input, char **command, char **arg)
{
    int i = 0;

    for (; input[i] && input[i] != ' '; i++);
    (*arg) = ((input[i]) ? &(input[i + 1]) : NULL);
    input[i] = '\0';
    client->delim = i;
    (*command) = input;
}

void analyse_input(t_client *client)
{
    char *input = NULL;
    char **com = NULL;

    input = get_input(client);
    if (!input)
        stop_program(1, NULL, NULL);
    if (check_miss_quote(input)) {
        write(2, "Miss Quote\n", 11);
        free(input);
        return;
    }
    com = parse_input(input);
    remove_quote(com);
    launch_command(client, com);
    if (input)
        free(input);
    free_array(com);
    client->str = NULL;
}

void launch_client(t_client *client)
{
    int ret = 0;

    while (client->is_connected) {
        print_prompt(client);
        FD_ZERO(&client->set);
        FD_SET(0, &client->set);
        FD_SET(client->fd, &client->set);
        ret = select(client->fd + 1, &client->set, NULL, NULL, NULL);
        if (ret < 0 && errno != EINTR)
            write(1, "select error\n", 13);
        if (errno == EINTR)
            continue;
        if (FD_ISSET(0, &client->set))
            analyse_input(client);
        if (FD_ISSET(client->fd, &client->set))
            analyse_answer(client);
    }
}