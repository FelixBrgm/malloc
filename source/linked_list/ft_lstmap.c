/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:47:39 by fbruggem          #+#    #+#             */
/*   Updated: 2022/03/31 14:09:52 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mem;
	t_list	*res;

	if (lst == NULL || f == NULL)
		return (NULL);
	res = NULL;
	while (lst)
	{
		mem = ft_lstnew(f(lst->content));
		if (mem == NULL)
		{
			ft_lstclear(&mem, del);
			return (NULL);
		}
		ft_lstadd_back(&res, mem);
		lst = lst->next;
	}
	return (res);
}
