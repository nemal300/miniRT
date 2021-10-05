/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:51:39 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:48:49 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	plst = *lst;
	while (plst->next)
		plst = plst->next;
	if (new)
	{
		new->next = NULL;
		plst->next = new;
	}
	return ;
}
