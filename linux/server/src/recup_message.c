/*
** EPITECH PROJECT, 2021
** server
** File description:
** recup_message
*/

#include "../include/my.h"

void recup_mess_line(t_control *control, char *line)
{
    char c = line[0];
    char **arr = cut_str_array(line, c);
    t_info *info = find_info_uid(control->head_info, arr[0]);
    t_mess *mess = NULL;
    int len = my_array_len(arr);

    if (!info)
        return;
    if (len != 4)
        return;
    mess = create_mess(arr[1], arr[3], atol(arr[2]), c);
    add_mess_list(info, mess);
    free_array(arr);
}

void recup_message(t_control *control)
{
    int fd = open(".message.conf", O_RDONLY | O_CREAT, 0777);
    char **arr = NULL;
    struct stat info;
    char *str = NULL;
    int ret = 0;

    if (fd == -1)
        return;
    fstat(fd, &info);
    str = (char *)malloc(sizeof(char) * (info.st_size + 1));
    ret = read(fd, str, info.st_size);
    str[ret] = '\0';
    arr = cut_str_array(str, '\n');
    for (int i = 0; arr[i]; i++)
        recup_mess_line(control, arr[i]);
    free_array(arr);
    free(str);
    close(fd);
}