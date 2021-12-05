/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** my_send
*/

#include "../include/my.h"

void my_send(int fd, char *message)
{
    write(fd, message, strlen(message));
}