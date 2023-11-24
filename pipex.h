/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:45:26 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/06 10:14:27 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_pipe_lists
{
	int					fd_input;
	int					fd_output;
	char				*name_file_input;
	char				*name_file_output;
	int					pipex_new[2];
	int					*pid;
	int					num_of_process;
	struct s_list_cmd	*head;
	struct s_list_cmd	*current;
}						t_pipe_lists;

typedef struct s_list_cmd
{
	int					check_permission;
	int					length_all_path;
	char				*path;
	char				**cmd;
	struct s_list_cmd	*next;
}						t_list_cmd;
//all_process
void					last_process(t_pipe_lists **list_pipe_main, char **envp,
							char *argv[], int argc);
void					middle_process(t_pipe_lists **list_pipe_main,
							char **envp, int i);
void					fork_process(t_pipe_lists **list_pipe_main, char **envp,
							char *argv[], int argc);
void					first_process(t_pipe_lists **list_pipe_main,
							char **envp, char *argv[], int argc);
//all_process_1
void					copy_pipex_new_to_old(t_pipe_lists **list_pipe_main);
void					error_create_pipe(void);
//init_lst
t_list_cmd				*ft_init_list_cmd_first_malloc(char **argv, int i);
t_list_cmd				*ft_init_list_cmd_next_malloc(char **argv, int i);
t_list_cmd				*ft_init_list_cmd(char *argv[], int argc);
void					ft_init_list_cmd_path(char **path_all,
							t_list_cmd **list_cmd_main, char ***path_all_main);
t_pipe_lists			*ft_init_list_pipe(t_list_cmd **list_cmd_main,
							char *argv[], int argc);
//all_process_1
char					*path_string(char ***path_all_main, char **cmd, int i,
							t_list_cmd **list_cmd_main);
void					create_path_null(t_list_cmd **list_cmd_main);
void					create_path_to_list_cmd(t_list_cmd **list_cmd_main, \
		char **path_all, char ***path_all_main);
//utils
char					*find_path(char **envp);
int						ft_len_all_path(char **path_all);
int						ft_len_list_cmd(t_list_cmd *head);
void					error_cmd(char ***path_all, t_list_cmd **list_cmd_main);
//utils1
void					close_all_pipe(t_pipe_lists **list_pipe_main);
int						wait_all_process(t_pipe_lists **list_pipe_main);
char					**crate_pathall(char **envp);
void					error_argc(char *msg);
//free
void					free_all_listcmd_caseone(t_list_cmd **list_cmd_main);
void					free_all_listcmd_casezero(t_list_cmd **list_cmd_main);
void					free_all_list_cmd(t_list_cmd **list_cmd_main,
							int case_num);
void					freelistcmd_and_pathall_msg(t_list_cmd **list_cmd_main, \
		char ***path_all_main, char *msg);
//free_1
void					free_path_all(char ***path_all_main);
void					free_list_pipe(t_pipe_lists **list_pipe_main);
//error_free
void					error_execve(char **cmd, t_pipe_lists **list_pipe_main,
							char *path, int length_all_path);
void					error_open_file_input(t_pipe_lists **list_pipe_main);
void					error_freelistcmd_andlistpipe(t_list_cmd **list_cmd, \
		t_pipe_lists **list_pipe, char *msg);
void					error_open_file_output(t_pipe_lists **list_pipe_main);
void					case_print(int case_print, char **cmd);
//error_free_1
void					error_execve_2(char **cmd,
							t_pipe_lists **list_pipe_main, char *path,
							int length_all_path);
void					error_execve_1(char **cmd, \
						t_pipe_lists **list_pipe_main, char *path);
#endif
