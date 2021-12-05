/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** the header file that countains function's prototype
*/

#ifndef CHECK_PROTO
    #define CHECK_PROTO 5
#include "libra.h"
#include "structure.h"
void launch_messages(t_client *client, char **arg);
void recv_send(char **arg);
void launch_send(t_client *client, char **arg);
char get_del(char *del, char *input);
void launch_user(t_client *client, char **arg);
void recv_login(char **arg);
void recv_logout(char **arg);
void remove_quote(char **arg);
bool check_miss_quote(char *input);
char **parse_input(char *input);
char **recup_in_arr(char *str);
void error_arg(void);
void function_unknown(void);
void launch_users(t_client *client, char **arg);
void analyse_answer(t_client *client);
void free_array(char **array);
char **cut_str_array(char *str, char c);
int count_char(char *str, char c);
bool check_client_arg(char *arg, int nb);
void launch_help(t_client *client, char **arg);
void launch_login(t_client *client, char **arg);
void stop_program(int sig, siginfo_t *info, void *buff);
void initialize_client_sig(t_client *client);
t_client *save_client(t_client *memory);
void free_client(t_client *client);
void launch_command(t_client *client, char **arg);
void launch_logout(t_client *client, char **arg);
void initialize_client_func(t_client *client);
void launch_client(t_client *client);
void initialize_client(t_client *client, char *host, int port);
bool is_arg_empty(char *arg);
void my_send(int fd, char *message);
t_client *create_client(int fd);
void exit_error(char *message);
int create_socket(void);
void check_error(int argc, char **argv);
int get_size_file(char *path);
void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
void my_put_nbr(int nbr);
int my_getnbr(char const *str);
int raising(int nbr, int n);
char *put_nbr_str(int nbr);
int my_array_len(char **array);
bool my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
char *my_strconcat(char *str1, char *str2);
char *get_file_content(char *path);
int count_char(char *str, char c);
char *my_strdup_char(char *str, char c);
char **cut_str_array(char *str, char c);
#endif
