/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** exit_error
*/

#include "../include/my.h"

void exit_error(char *message)
{
    perror(message);
    exit(84);
}