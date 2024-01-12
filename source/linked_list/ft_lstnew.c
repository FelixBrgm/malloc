/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:15:03 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/09 16:12:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>
t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = mmap(NULL, sizeof(t_list), PROT_WRITE | PROT_READ, 0x20 | MAP_PRIVATE, -1, 0);
 
	if (res == NULL)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
