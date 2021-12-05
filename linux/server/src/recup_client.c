/*
** EPITECH PROJECT, 2021
** server
** File description:
** recup_client
*/

#include "../include/my.h"

void recup_cli_line(t_control *control, char *str)
{
    char c = '%';
    int nb = count_char(str, c);
    char **arg = NULL;
    t_info *info = NULL;

    if (nb != 1)
        return;
    arg = cut_str_array(str, c);
    info =  create_info(arg[0], arg[1]);
    add_info_list(control, info);
    server_event_user_loaded(arg[0], arg[1]);
    free_array(arg);
}

void recup_client(t_control *control, int fd)
{
    struct stat info;
    char *str = NULL;
    char **arr = NULL;
    int ret = 0;

    if (stat(".client.conf", &info) == -1) {
        my_putstr("[NO FILE]");
        return;
    }
    str = (char *)malloc(sizeof(char) * (info.st_size + 1));
    ret = read(fd, str, info.st_size);
    str[ret] = '\0';
    arr = cut_str_array(str, '\n');
    for (int i = 0; arr[i]; i++) {
        recup_cli_line(control, arr[i]);
    }
    free_array(arr);
    free(str);
}