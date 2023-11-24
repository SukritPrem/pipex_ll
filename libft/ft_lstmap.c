/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:27:12 by spipitku          #+#    #+#             */
/*   Updated: 2023/09/03 20:27:41 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_clear;

	if (!lst)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	new_lst_clear = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&new_lst_clear, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new_lst_clear);
}

// #include <stdio.h>
// void  *returnok(void *content){
//   return("OK !");
// }

// int main(void)
// {
//   t_list  *l = ft_lstnew(ft_strdup(" 1 2 3 4"));
//   l->next = ft_lstnew(ft_strdup("ss"));
//   l->next->next = ft_lstnew(ft_strdup("Hello"));
//   t_list  *tmp = l;
//   while(tmp)
//   {
//     printf("%s\n",tmp->content);
//     tmp = tmp->next;
//   }
//   tmp = l;
//   t_list  *ret = ft_lstmap(l, returnok, del);
//   while(ret)
//   {
//     printf("%s\n",ret->content);
//     ret = ret->next;
//   }
//   return (0);
// }
