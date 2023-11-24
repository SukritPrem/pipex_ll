/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:00:11 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/02 13:44:01 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path_all(char ***path_all_main)
{
	int		i;
	char	**path_all;

	path_all = *path_all_main;
	i = 0;
	while (path_all[i])
	{
		free(path_all[i]);
		i++;
	}
	free(path_all);
}

void	free_list_pipe(t_pipe_lists **list_pipe_main)
{
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	if (list_pipe->head)
		free_all_list_cmd(&list_pipe->head, 1);
	if (list_pipe->num_of_process != 0)
		free(list_pipe->pid);
	if (list_pipe->name_file_input)
		free(list_pipe->name_file_input);
	if (list_pipe->name_file_output)
		free(list_pipe->name_file_output);
	free(list_pipe);
}
