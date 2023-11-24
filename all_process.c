/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:14:55 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/06 10:14:49 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	try_exec(char **cmd, char **envp)
{
	char	*argv_clone[3];

	if (errno == ENOEXEC)
	{
		argv_clone[0] = "/bin/bash";
		argv_clone[1] = cmd[0];
		argv_clone[2] = NULL;
		execve(argv_clone[0], argv_clone, envp);
	}
}

void	first_process(t_pipe_lists **list_pipe_main, char **envp, char *argv[],
		int argc)
{
	t_pipe_lists	*list_pipe;

	(void)argc;
	list_pipe = *list_pipe_main;
	list_pipe->current = list_pipe->head;
	list_pipe->fd_input = open(argv[1], O_RDONLY);
	if (list_pipe->fd_input < 0)
		error_open_file_input(&list_pipe);
	dup2(list_pipe->fd_input, STDIN_FILENO);
	dup2(list_pipe->pipex_new[1], STDOUT_FILENO);
	close(list_pipe->pipex_new[0]);
	close(list_pipe->pipex_new[1]);
	error_execve(list_pipe->current->cmd, \
			&list_pipe, list_pipe->current->path, \
			list_pipe->current->length_all_path);
	if (execve(list_pipe->current->path, list_pipe->current->cmd, envp) == -1)
	{
		if (errno == ENOEXEC)
			try_exec(list_pipe->current->cmd, envp);
		free_list_pipe(&list_pipe);
		exit(0);
	}
}

void	last_process(t_pipe_lists **list_pipe_main, char **envp, char *argv[],
		int argc)
{
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	list_pipe->current = list_pipe->head;
	list_pipe->fd_output = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY,
			0644);
	while (list_pipe->current->next)
		list_pipe->current = list_pipe->current->next;
	if (list_pipe->fd_output < 0)
		error_open_file_output(&list_pipe);
	dup2(list_pipe->fd_output, STDOUT_FILENO);
	close(list_pipe->pipex_new[0]);
	close(list_pipe->pipex_new[1]);
	error_execve(list_pipe->current->cmd, &list_pipe, \
			list_pipe->current->path, \
			list_pipe->current->length_all_path);
	if (execve(list_pipe->current->path, list_pipe->current->cmd, envp) == -1)
	{
		if (errno == ENOEXEC)
			try_exec(list_pipe->current->cmd, envp);
		free_list_pipe(&list_pipe);
		exit(0);
	}
}

void	middle_process(t_pipe_lists **list_pipe_main, char **envp, int i)
{
	t_pipe_lists	*list_pipe;
	int				j;

	list_pipe = *list_pipe_main;
	list_pipe->current = list_pipe->head;
	j = 0;
	while (j < i)
	{
		list_pipe->current = list_pipe->current->next;
		j++;
	}
	dup2(list_pipe->pipex_new[1], STDOUT_FILENO);
	close(list_pipe->pipex_new[0]);
	close(list_pipe->pipex_new[1]);
	error_execve(list_pipe->current->cmd, \
			&list_pipe, list_pipe->current->path, \
			list_pipe->current->length_all_path);
	if (execve(list_pipe->current->path, list_pipe->current->cmd, envp) == -1)
	{
		if (errno == ENOEXEC)
			try_exec(list_pipe->current->cmd, envp);
		free_list_pipe(&list_pipe);
		exit(0);
	}
}

void	fork_process(t_pipe_lists **list_pipe_main, char **envp, char *argv[],
		int argc)
{
	int				i;
	t_pipe_lists	*list_pipe;

	list_pipe = *list_pipe_main;
	i = 0;
	while (i < list_pipe->num_of_process)
	{
		if (pipe(list_pipe->pipex_new) == -1)
			error_freelistcmd_andlistpipe(NULL, &list_pipe, "err func pipe\n");
		list_pipe->pid[i] = fork();
		if (list_pipe->pid[i] == -1)
			error_create_pipe();
		if (list_pipe->pid[i] == 0)
		{
			if (i == 0)
				first_process(&list_pipe, envp, argv, argc);
			else if (i == list_pipe->num_of_process - 1)
				last_process(&list_pipe, envp, argv, argc);
			else
				middle_process(&list_pipe, envp, i);
		}
		else
			copy_pipex_new_to_old(list_pipe_main);
		i++;
	}
}
