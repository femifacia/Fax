/*
** EPITECH PROJECT, 2021
** server
** File description:
** save_client
*/

#include "../include/my.h"

void save_client(t_info *info)
{
    int fd = open(".client.conf", O_WRONLY | O_CREAT, 0777);

    for (;info; info = info->next) {
        if (info->name)
            write(fd, info->name, strlen(info->name));
        write(fd, "%", 1);
        if (info->uid)
            write(fd, info->uid, strlen(info->uid));
        write(fd, "\n", 1);
    }
    close(fd);
}