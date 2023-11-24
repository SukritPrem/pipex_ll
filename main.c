/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:15:23 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/04 10:37:40 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	char			**path_all;
	t_pipe_lists	*list_pipe;
	t_list_cmd		*list_cmd;
	int				stat_last;

	if (argc < 5)
		error_argc("Error to few arguments in program pipex\n");
	path_all = crate_pathall(envp);
	list_cmd = ft_init_list_cmd(argv, argc);
	if (list_cmd == NULL)
		freelistcmd_and_pathall_msg(&list_cmd, &path_all, \
				"Error creating list cmd \n");
	ft_init_list_cmd_path(path_all, &list_cmd, &path_all);
	if (path_all)
		free_path_all(&path_all);
	list_pipe = ft_init_list_pipe(&list_cmd, argv, argc);
	fork_process(&list_pipe, envp, argv, argc);
	stat_last = wait_all_process(&list_pipe);
	free_list_pipe(&list_pipe);
	return (stat_last);
}
