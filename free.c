/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:45:51 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/03 11:14:29 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all_listcmd_caseone(t_list_cmd **list_cmd_main)
{
	t_list_cmd	*list_cmd;
	t_list_cmd	*clone;
	int			i;

	i = 0;
	list_cmd = *list_cmd_main;
	while (list_cmd)
	{
		clone = list_cmd->next;
		if (list_cmd->cmd)
		{
			i = 0;
			if (list_cmd->cmd[i])
			{
				while (list_cmd->cmd[i])
					free(list_cmd->cmd[i++]);
			}
			free(list_cmd->cmd);
		}
		if (list_cmd->path)
			free(list_cmd->path);
		free(list_cmd);
		list_cmd = clone;
	}
}

void	free_all_listcmd_casezero(t_list_cmd **list_cmd_main)
{
	t_list_cmd	*list_cmd;
	t_list_cmd	*clone;
	int			i;

	i = 0;
	list_cmd = *list_cmd_main;
	while (list_cmd)
	{
		clone = list_cmd->next;
		if (list_cmd->cmd)
		{
			i = 0;
			if (list_cmd->cmd[i])
			{
				while (list_cmd->cmd[i])
					free(list_cmd->cmd[i++]);
			}
			free(list_cmd->cmd);
		}
		free(list_cmd);
		list_cmd = clone;
	}
}

void	free_all_list_cmd(t_list_cmd **list_cmd_main, int case_num)
{
	if (case_num == 0)
		free_all_listcmd_casezero(list_cmd_main);
	else if (case_num == 1)
		free_all_listcmd_caseone(list_cmd_main);
}

void	freelistcmd_and_pathall_msg(t_list_cmd **list_cmd_main,
									char ***path_all_main,
									char *msg)
{
	ft_putstr_fd(msg, 2);
	free_all_list_cmd(list_cmd_main, 1);
	free_path_all(path_all_main);
	exit(1);
}
