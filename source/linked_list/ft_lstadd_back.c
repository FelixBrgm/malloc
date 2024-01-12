/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:32:02 by fbruggem          #+#    #+#             */
/*   Updated: 2022/10/24 14:50:08 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mem;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			mem = ft_lstlast(*lst);
			mem->next = new;
		}
	}
}
