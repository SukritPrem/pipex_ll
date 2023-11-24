/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:55:26 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/04 14:33:17 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_freelistcmd_andlistpipe(t_list_cmd **list_cmd, \
		t_pipe_lists **list_pipe, char *msg)
{
	ft_putstr_fd(msg, 2);
	if (list_cmd)
		free_all_list_cmd(list_cmd, 1);
	free_list_pipe(list_pipe);
	exit(1);
}

void	error_execve(char **cmd, t_pipe_lists **list_pipe_main, char *path,
		int length_all_path)
{
	if (ft_strchr(cmd[0], '/'))
		error_execve_1(cmd, list_pipe_main, path);
	else
		error_execve_2(cmd, list_pipe_main, path, length_all_path);
}

void	case_print(int case_print, char **cmd)
{
	if (case_print == 0)
	{
		write(2, "no such file or directory: ", 27);
		ft_putstr_fd(cmd[0], 2);
		write(2, "\n", 1);
	}
	else if (case_print == 1)
	{
		write(2, "command not found: ", 20);
		ft_putstr_fd(cmd[0], 2);
		write(2, "\n", 1);
	}
	else if (case_print == 3)
	{
		write(2, "Permission denied :", 20);
		ft_putstr_fd(cmd[0], 2);
		write(2, "\n", 1);
	}
}

void	error_open_file_input(t_pipe_lists **list_pipe_main)
{
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	perror(list_pipe->name_file_input);
	free_list_pipe(list_pipe_main);
	exit(1);
}

void	error_open_file_output(t_pipe_lists **list_pipe_main)
{
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	perror(list_pipe->name_file_output);
	free_list_pipe(list_pipe_main);
	exit(1);
}
