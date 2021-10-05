/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:49:17 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:25:43 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;
	int				i;

	i = 0;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
		{
			ds[len] = sr[len];
		}
	}
	return (dst);
}
