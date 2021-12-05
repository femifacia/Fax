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
void launch_messages(t_control *control, t_client *cli, char *arg);
void recup_message(t_control *control);
void my_putstr_fd(char *str, int fd);
void save_message(t_info *info);
void add_mess_list(t_info *info, t_mess *mess);
t_mess *create_mess(char *uid, char *str, time_t time, char c);
void launch_send(t_control *control, t_client *client, char *arg);
t_info *find_info_uid(t_info *info, char *uid);
void cut_quote(char **arg);
void launch_users(t_control *control, t_client *client, char *arg);
void save_client(t_info *info);
void save_info(t_control *control);
t_info *find_info(t_info *info, char *name);
t_client *find_client(t_client *client, char *name);
void add_info_list(t_control *control, t_info *info);
t_info *create_info(char *name, char *uid);
void recup_client(t_control *control, int fd);
void recup_data(t_control *control);
void launch_login(t_control *control, t_client *client, char *arg);
void launch_logout(t_control *control, t_client *client, char *arg);
void launch_teams(t_control *control);
void initialize_sig(void);
t_control *save_control(t_control *memory);
void launch_list(t_control *control, t_client *client, char *argv);
void launch_dele(t_control *control, t_client *client, char *arg);
void launch_cwd(t_control *control, t_client *client, char *arg);
void launch_cdup(t_control *control, t_client *client, char *arg);
void launch_pwd(t_control *control, t_client *client, char *arg);
void launch_noop(t_control *control, t_client *client, char *arg);
void launch_help(t_control *control, t_client *client, char *arg);
bool is_arg_empty(char *arg);
void launch_user(t_control *control, t_client *client, char *arg);
void launch_pass(t_control *control, t_client *client, char *arg);
void launch_command(t_control *control, t_client *client, char *com, char *arg);
void launch_quit(t_control *control, t_client *client, char *arg);
void manage_client(t_client *client, t_control *control);
void my_send(int fd, char *message);
void add_client_list(t_control *control, t_client *client);
t_client *create_client(int fd);
void launch_ftp(t_control *control);
void free_control(t_control *control);
t_control *initialize_control(char *port);
void exit_error(char *message);
int create_socket(void);
void check_error(char **argv);
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
void free_array(char **array);
char *my_strdup_char(char *str, char c);
char **cut_str_array(char *str, char c);
#endif
