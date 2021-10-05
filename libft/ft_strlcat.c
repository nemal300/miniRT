/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:51:41 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:26:40 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t res;
	size_t i;

	res = ft_strlen(dst);
	if (res >= dstsize)
		return (ft_strlen(src) + dstsize);
	else
	{
		dst += res;
		res += ft_strlen(src);
		i = 0;
		while ((dstsize - (res - ft_strlen(src)) - 1) > i && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (res);
}
