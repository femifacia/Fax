/*
** EPITECH PROJECT, 2021
** client
** File description:
** initialize_client_sig
*/

#include "../include/my.h"

void stop_program(int sig, siginfo_t *info, void *buff)
{
    t_client *client = save_client(NULL);

    write(1, "\n", 1);
    launch_logout(client, NULL);
    free_client(client);
    exit(0);
}

void initialize_client_sig(t_client *client)
{
    struct sigaction old;
    struct sigaction new;

    memset(&new, 0, sizeof(struct sigaction));
    memset(&old, 0, sizeof(struct sigaction));
    new.sa_flags = SA_SIGINFO;
    sigemptyset(&new.sa_mask);
    new.sa_sigaction = &stop_program;
    sigaction(SIGINT, &new, &old);
}