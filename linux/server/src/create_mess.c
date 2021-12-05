/*
** EPITECH PROJECT, 2021
** server
** File description:
** create_mess
*/

#include "../include/my.h"

void add_mess_list(t_info *info, t_mess *mess)
{
    if (!info->head_mess)
        info->head_mess = mess;
    else {
        if (!info->tail_mess) {
            info->head_mess->next = mess;
            mess->prev = info->head_mess;
        } else {
            info->tail_mess->next = mess;
            mess->prev = info->tail_mess;
        }
        info->tail_mess = mess;
    }
}

t_mess *create_mess(char *uid, char *str, time_t time, char c)
{
    t_mess *mess = (t_mess *)malloc(sizeof(t_mess));

    mess->next = NULL;
    mess->prev = NULL;
    mess->time = time;
    mess->from_uid = strdup(uid);
    mess->mess = strdup(str);
    mess->c = c;
    return (mess);
}
