/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:58:11 by fbruggem          #+#    #+#             */
/*   Updated: 2022/10/24 14:50:39 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*mem;

	mem = NULL;
	while (lst != NULL && *lst != NULL)
	{
		(*del)((*lst)->content);
		mem = (*lst)->next;
		munmap(*lst, sizeof(t_list));
		*lst = mem;
	}
}
