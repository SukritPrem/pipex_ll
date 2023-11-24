/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:18:46 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/03 18:37:34 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_all_process(t_pipe_lists **list_pipe_main)
{
	t_pipe_lists	*list_pipe;
	int				i;
	int				stat;

	i = 0;
	list_pipe = *list_pipe_main;
	while (i < list_pipe->num_of_process - 1)
	{
		waitpid(list_pipe->pid[i], NULL, 0);
		i++;
	}
	waitpid(list_pipe->pid[list_pipe->num_of_process - 1], &stat, 0);
	return (WEXITSTATUS(stat));
}

char	**crate_pathall(char **envp)
{
	char	*path;
	char	**path_all;

	path_all = NULL;
	path = find_path(envp);
	if (path != NULL)
		path_all = ft_split(path, ':');
	return (path_all);
}

void	error_argc(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}
