/*
** EPITECH PROJECT, 2021
** server
** File description:
** find_info
*/

#include "../include/my.h"

t_info *find_info_uid(t_info *info, char *uid)
{
    for (; info; info = info->next) {
        if (!info->uid)
            continue;
        if (!strcmp(uid, info->uid))
            return (info);
    }
    return (NULL);
}

t_info *find_info(t_info *info, char *name)
{
    for (; info; info = info->next) {
        if (!info->name)
            continue;
        if (!strcmp(name, info->name))
            return (info);
    }
    return (NULL);
}