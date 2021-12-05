/*
** EPITECH PROJECT, 2021
** server
** File description:
** create_info
*/

#include "../include/my.h"

void add_info_list(t_control *control, t_info *info)
{
    if (!control->head_info)
        control->head_info = info;
    else {
        if (!control->tail_info) {
            control->head_info->next = info;
            info->prev = control->head_info;
        } else {
            control->tail_info->next = info;
            info->prev = control->tail_info;
        }
        control->tail_info = info;
    }
}

t_info *create_info(char *name, char *uid)
{
    t_info *info = (t_info *)malloc(sizeof(t_info));

    info->next = NULL;
    info->prev = NULL;
    info->name = ((name) ? strdup(name) : NULL);
    info->status = 0;
    if (!uid) {
        uuid_generate_random(info->binuuid);
        info->uid = (char *)malloc(sizeof(char) * 37);
        uuid_unparse(info->binuuid, info->uid);
    } else
        info->uid = strdup(uid);
    info->head_mess = NULL;
    info->tail_mess = NULL;
    return (info);
}