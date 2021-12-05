/*
** EPITECH PROJECT, 2021
** server
** File description:
** recup_data
*/

#include "../include/my.h"

void recup_data(t_control *control)
{
    int fd = open(".client.conf", O_RDONLY | O_CREAT, 0777);

    if (fd < 0) {
        my_putstr("[NO FILE]\n");
        return;
    }
    recup_client(control, fd);
    recup_message(control);
    close(fd);
}