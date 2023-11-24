/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_process_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:42:23 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/06 10:14:34 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	copy_pipex_new_to_old(t_pipe_lists **list_pipe_main)
{
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	dup2(list_pipe->pipex_new[0], STDIN_FILENO);
	close(list_pipe->pipex_new[0]);
	close(list_pipe->pipex_new[1]);
}

void	error_create_pipe(void)
{
	ft_putstr_fd("Error with creating process\n", 2);
	exit(1);
}

void	create_path_to_list_cmd(t_list_cmd **list_cmd_main, char **path_all,
		char ***path_all_main)
{
	int			i;
	t_list_cmd	*list_cmd;

	i = 0;
	list_cmd = *list_cmd_main;
	list_cmd->length_all_path = ft_len_all_path(path_all);
	while (path_all[i])
	{
		if (list_cmd->cmd[0] == NULL)
		{
			list_cmd->path = NULL;
			break ;
		}
		list_cmd->path = path_string(path_all_main, &list_cmd->cmd[0], i,
				list_cmd_main);
		if (access(list_cmd->path, F_OK) != -1)
			break ;
		free(list_cmd->path);
		i++;
		if (i == list_cmd->length_all_path)
			list_cmd->path = NULL;
	}
}

void	create_path_null(t_list_cmd **list_cmd_main)
{
	t_list_cmd	*list_cmd;

	list_cmd = *list_cmd_main;
	list_cmd->path = NULL;
	list_cmd->length_all_path = 0;
}

char	*path_string(char ***path_all_main, char **cmd, int i,
		t_list_cmd **list_cmd_main)
{
	char	*path_slash;
	char	**path_all;
	char	*path;

	path_all = *path_all_main;
	path = NULL;
	if (!ft_strchr(cmd[0], '/'))
	{
		path_slash = ft_strjoin(path_all[i], "/");
		if (path_slash == NULL)
			freelistcmd_and_pathall_msg(list_cmd_main, \
					path_all_main, "Error creating join / path\n");
		path = ft_strjoin(path_slash, cmd[0]);
		if (path == NULL)
			freelistcmd_and_pathall_msg(list_cmd_main, \
					path_all_main, "Error creating join path\n");
		free(path_slash);
	}
	else
		path = ft_strdup(cmd[0]);
	return (path);
}
