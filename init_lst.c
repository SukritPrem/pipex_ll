/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:15 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/04 15:15:56 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list_cmd	*ft_init_list_cmd_first_malloc(char **argv, int i)
{
	t_list_cmd	*list_cmd;

	list_cmd = malloc(sizeof(t_list_cmd));
	if (list_cmd == NULL)
		exit(1);
	list_cmd->cmd = ft_split(argv[i], ' ');
	list_cmd->next = NULL;
	return (list_cmd);
}

t_list_cmd	*ft_init_list_cmd_next_malloc(char **argv, int i)
{
	t_list_cmd	*list_cmd;

	list_cmd = malloc(sizeof(t_list_cmd));
	if (list_cmd == NULL)
		return (NULL);
	list_cmd->cmd = ft_split(argv[i], ' ');
	list_cmd->next = NULL;
	return (list_cmd);
}

t_list_cmd	*ft_init_list_cmd(char *argv[], int argc)
{
	int			i;
	t_list_cmd	*list_cmd;
	t_list_cmd	*clone;
	t_list_cmd	*clone_next;

	list_cmd = NULL;
	i = 2;
	while (i < argc - 1)
	{
		if (list_cmd == NULL)
		{
			list_cmd = ft_init_list_cmd_first_malloc(argv, i);
			clone_next = list_cmd;
		}
		else
		{
			clone = ft_init_list_cmd_next_malloc(argv, i);
			if (clone == NULL)
				return (NULL);
			clone_next->next = clone;
			clone_next = clone;
		}
		i++;
	}
	return (list_cmd);
}

void	ft_init_list_cmd_path(char **path_all, t_list_cmd **list_cmd_main,
		char ***path_all_main)
{
	t_list_cmd	*list_cmd;
	t_list_cmd	*head;

	list_cmd = *list_cmd_main;
	head = list_cmd;
	while (list_cmd)
	{
		if (path_all)
			create_path_to_list_cmd(&list_cmd, path_all, path_all_main);
		if (path_all == NULL)
			create_path_null(&list_cmd);
		list_cmd = list_cmd->next;
	}
	list_cmd_main = &head;
}

t_pipe_lists	*ft_init_list_pipe(t_list_cmd **list_cmd_main, char *argv[],
		int argc)
{
	t_pipe_lists	*list_pipe;

	list_pipe = malloc(sizeof(t_pipe_lists));
	list_pipe->num_of_process = 0;
	if (list_pipe == NULL)
		error_freelistcmd_andlistpipe(list_cmd_main, &list_pipe, \
				"Error malloc list_pipe\n");
	list_pipe->head = *list_cmd_main;
	list_pipe->name_file_input = ft_strdup(argv[1]);
	list_pipe->name_file_output = ft_strdup(argv[argc - 1]);
	list_pipe->num_of_process = ft_len_list_cmd(list_pipe->head);
	list_pipe->pid = malloc(sizeof(int) * list_pipe->num_of_process);
	return (list_pipe);
}
