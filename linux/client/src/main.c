/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** main
*/

#include "../include/my.h"

void print_help(void)
{
    printf("USAGE: ./fax_cli ip port\n");
    printf("\tip is the server ip address on");
    printf(" which the server socket listens\n");
    printf("\tport is the port number on");
    printf(" which the server socket listens\n");
    exit(0);
}

void check_error(int argc, char **argv)
{
    if (argc != 3)
        exit(84);
    for (int i = 0; argv[2][i]; i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9')
            exit(84);
    }
}

t_client *save_client(t_client *memory)
{
    static t_client *client = NULL;

    if (memory)
        client = memory;
    return (client);
}

int main(int argc, char **argv)
{
    t_client client;

    if (argc == 2) {
        if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h") || !strcmp(argv[1], "-help"))
            print_help();
    }
    check_error(argc, argv);
    memset(&client, 0, sizeof(t_client));
    initialize_client(&client, argv[1], atoi(argv[2]));
    initialize_client_func(&client);
    initialize_client_sig(&client);
    save_client(&client);
    launch_client(&client);
    free_client(&client);
    return (0);
}