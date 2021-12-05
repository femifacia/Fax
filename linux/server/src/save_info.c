/*
** EPITECH PROJECT, 2021
** server
** File description:
** save_info
*/

#include "../include/my.h"

void save_info(t_control *control)
{
    save_client(control->head_info);
    save_message(control->head_info);
}