/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:54:06 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 12:55:32 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	munmap(lst, sizeof(t_list));}
