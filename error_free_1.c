/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:45:13 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/08 09:23:54 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_execve_1(char **cmd, t_pipe_lists **list_pipe_main, char *path)
{
	if ((access(path, X_OK) == 0 && access(path, R_OK) == -1)
		|| (access(path, X_OK) == -1 && access(path, R_OK) == 0)
		|| (access(path, X_OK) == -1 && access(path, W_OK) == 0)
		|| (access(path, X_OK) == -1 && access(path, W_OK) == -1
			&& access(path, R_OK) == -1 && access(path, F_OK) == 0))
	{
		case_print(3, cmd);
		free_list_pipe(list_pipe_main);
		exit(126);
	}
	if (access(path, F_OK) == -1)
	{
		case_print(0, cmd);
		free_list_pipe(list_pipe_main);
		exit(127);
	}
}

void	error_execve_2(char **cmd, t_pipe_lists **list_pipe_main, char *path,
		int length_all_path)
{
	if ((access(path, X_OK) == 0 && access(path, R_OK) == -1) \
			|| (access(path, X_OK) == -1 && access(path, R_OK) == 0) \
			|| (access(path, X_OK) == -1 && access(path, W_OK) == 0) \
			|| (access(path, X_OK) == -1 && access(path, W_OK) == -1 \
				&& access(path, R_OK) == -1 && access(path, F_OK) == 0))
	{
		case_print(3, cmd);
		free_list_pipe(list_pipe_main);
		exit(126);
	}
	if (access(path, F_OK) == -1 && path == NULL && length_all_path == 0)
	{
		case_print(0, cmd);
		free_list_pipe(list_pipe_main);
		exit(127);
	}
	else if (access(path, F_OK) == -1 && path == NULL && length_all_path > 0)
	{
		case_print(1, cmd);
		free_list_pipe(list_pipe_main);
		exit(127);
	}
}
