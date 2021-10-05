/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:27:15 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:27:09 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayst, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (*needle == '\0' || ft_strlen(needle) == 0)
		return ((char *)hayst);
	if (*hayst == '\0' || ft_strlen(hayst) == 0)
		return (NULL);
	while (i < len)
	{
		if (ft_strncmp(hayst, needle, ft_strlen(needle)) == 0)
			return ((char *)hayst);
		if (i + ft_strlen(needle) > len)
			return (NULL);
		hayst++;
		i++;
	}
	return (NULL);
}
