/*
** EPITECH PROJECT, 2021
** B-NWP-400-COT-4-1-myftp-femi.facia
** File description:
** initialize_control
*/

#include "../include/my.h"

void initialize_com_str(t_control *control)
{
    int size = 7;

    control->com_str = (char **)malloc(sizeof(char *) * size);
    control->com_str[0] = "/logout";
    control->com_str[1] = "/login";
    control->com_str[2] = "/users";
    control->com_str[3] = "/user";
    control->com_str[4] = "/send";
    control->com_str[5] = "/messages";
    control->com_str[size - 1] = NULL;
}

void initialize_com_func(t_control *control)
{
    int size = 7;

    control->com_func = malloc(sizeof(func_ptr) * size);
    control->com_func[0] = launch_logout;
    control->com_func[1] = launch_login;
    control->com_func[2] = launch_users;
    control->com_func[3] = launch_user;
    control->com_func[4] = launch_send;
    control->com_func[5] = launch_messages;
    control->com_func[size - 1] = NULL;
}

void initialize_ctrl_next(t_control *control, int sck)
{
    control->highest_socket = sck;
    control->head_client = NULL;
    control->tail_client = NULL;
    control->nb_client = 0;
    control->head_info = NULL;
    control->tail_info = NULL;
    initialize_com_str(control);
    initialize_com_func(control);
    initialize_sig();
}

t_control *initialize_control(char *port)
{
    t_control *control = (t_control *)malloc(sizeof(t_control));
    int sck = socket(AF_INET, SOCK_STREAM, 0);
    int ret = 0;

    control->port = atoi(port);
    control->addr_len = sizeof(struct sockaddr_in);
    control->addr_in.sin_port = htons(control->port);
    control->addr_in.sin_family = AF_INET;
    control->addr_in.sin_addr.s_addr = INADDR_ANY;
    ret = bind(sck, (struct sockaddr *)&(control->addr_in), control->addr_len);
    if (ret == -1)
        exit_error("create_socket");
    listen(sck, control->port);
    initialize_ctrl_next(control, sck);
    return (control);
}