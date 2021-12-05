/*
** EPITECH PROJECT, 2021
** server
** File description:
** save_message
*/

#include "../include/my.h"

void write_cli_mess(t_info *info, int fd)
{
    t_mess *mess = info->head_mess;
    char str[1024];

    for (; mess; mess = mess->next) {
        write(fd, &mess->c, 1);
        write(fd, info->uid, strlen(info->uid));
        write(fd, &mess->c, 1);
        write(fd, mess->from_uid, strlen(mess->from_uid));
        write(fd, &mess->c, 1);
        sprintf(str, "%ld", mess->time);
        my_putstr_fd(str, fd);
        write(fd, &mess->c, 1);
        my_putstr_fd(mess->mess, fd);
        write(fd, "\n", 1);
    }
}

void save_message(t_info *info)
{
    int fd = open(".message.conf", O_WRONLY | O_CREAT, 0777);

    if (fd == -1)
        return;
    for (;info; info = info->next)
        write_cli_mess(info, fd);
    close(fd);
}