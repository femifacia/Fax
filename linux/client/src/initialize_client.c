/*
** EPITECH PROJECT, 2021
** client
** File description:
** initialize_client
*/

#include "../include/my.h"

void init_client_str(t_client *client)
{
    int size = 8;

    client->com_str = (char **)malloc(sizeof(char *) * size);
    client->com_str[0] = "/logout";
    client->com_str[1] = "/login";
    client->com_str[2] = "/help";
    client->com_str[3] = "/users";
    client->com_str[4] = "/user";
    client->com_str[5] = "/send";
    client->com_str[6] = "/messages";
    client->com_str[size - 1] = NULL;
}

void init_client_func(t_client *client)
{
    int size = 8;

    client->com_func = malloc(sizeof(func_ptr) * size);
    client->com_func[0] = launch_logout;
    client->com_func[1] = launch_login;
    client->com_func[2] = launch_help;
    client->com_func[3] = launch_users;
    client->com_func[4] = launch_user;
    client->com_func[5] = launch_send;
    client->com_func[6] = launch_messages;
    client->com_str[size - 1] = NULL;
}

void initialize_client_func(t_client *client)
{
    init_client_str(client);
    init_client_func(client);
    client->is_connected = 1;
    client->is_logged = 0;
    client->delim = 0;
    client->str = NULL;
    client->name = NULL;
    client->uid = NULL;
}

void initialize_client(t_client *client, char *host, int port)
{
    int ret = 0;
    struct sockaddr *addr = (struct sockaddr *)&(client->serv_addr);

    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    client->is_logged = 1;
    if (client->fd == -1) {
        perror("Socket creation:");
        exit(84);
    }
    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(port);
    ret = inet_pton(AF_INET, host, &(client->serv_addr.sin_addr));
    if (ret <= 0) {
        perror("Addr conversion: ");
        exit(84);
    }
    if (connect(client->fd, addr, sizeof(client->serv_addr)) < 0) {
        perror("connection: ");
        exit(84);
    }
}