/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myteams-femi.facia
** File description:
** save_control
*/

#include "../include/my.h"

t_control *save_control(t_control *memory)
{
    static t_control *control = NULL;

    if (memory)
        control = memory;
    return (control);
}