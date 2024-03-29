/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** main
*/

#include "../include/my.h"

void print_help(int ret_val)
{
    printf("USAGE: ./fax_server port\n");
    printf("\tport is the port number on which");
    printf(" the server socket listens.\n");
    exit(ret_val);
}

void check_error(char **argv)
{
    for (int i = 0; argv[1][i]; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            print_help(84);
    }
}

int main(int argc, char **argv)
{
    t_control *control = NULL;

    if (argc != 2)
        print_help(84);
    if (!strcmp(argv[1], "-help") || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        print_help(0);
    check_error(argv);
    control = initialize_control(argv[1]);
    save_control(control);
    recup_data(control);
    launch_teams(control);
    free_control(control);
    return (0);
}