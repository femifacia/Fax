/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** initialize_sig
*/

#include "../include/my.h"

void stop_program(int sig, siginfo_t *info, void *buff)
{
    t_control *control = save_control(NULL);
    t_client *client = control->head_client;

    while (client) {
        if (client->fd)
            my_send(client->fd, "/logout");
        client = client->next;
    }
    if (control)
        free_control(control);
    exit(0);
}

void initialize_sig(void)
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