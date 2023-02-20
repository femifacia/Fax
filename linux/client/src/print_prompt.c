/*
** EPITECH PROJECT, 2023
** linux
** File description:
** print_prompt
*/

#include "../include/my.h"

void print_prompt(t_client *client)
{
    if (!client->is_logged) {
        my_putstr("\e[01;31m");
        my_putstr("[Not Logged] ");
        my_putstr("\e[00;00m");
    } else {
        my_putstr("\e[01;32m");
        my_putstr("[");
        my_putstr(client->name);
        my_putstr(" Logged] ");
        my_putstr("\e[00;00m");
    }
}