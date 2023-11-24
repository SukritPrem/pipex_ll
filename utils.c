/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:30:03 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/08 09:23:28 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (envp[i][0] == 'P')
		{
			if (ft_strnstr(envp[i], "PATH", 5))
			{
				path = ft_strnstr(envp[i], "PATH", 5);
				path = path + 5;
				break ;
			}
		}
		i++;
	}
	if (envp + i == NULL)
		return (NULL);
	return (path);
}

int	ft_len_all_path(char **path_all)
{
	int	i;

	i = 0;
	while (path_all[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	ft_len_list_cmd(t_list_cmd *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
