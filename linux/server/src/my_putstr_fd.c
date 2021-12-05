/*
** EPITECH PROJECT, 2021
** server
** File description:
** my_putstr_fd
*/

#include "../include/my.h"

void my_putstr_fd(char *str, int fd)
{
    write(fd, str, strlen(str));
}