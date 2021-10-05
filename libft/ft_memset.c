/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:24:08 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:24:37 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)memptr;
	while (len--)
	{
		*str = c;
		str++;
	}
	return (memptr);
}
