/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:25:12 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:19:07 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizes(const char *s1)
{
	int res;

	res = 0;
	while (*s1 != '\0')
	{
		res++;
		s1++;
	}
	return (res);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	ptr = malloc(sizes(s1) + sizes(s2) + 1);
	if (ptr == 0)
		return (0);
	while (*s1 != '\0')
	{
		ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		ptr[i] = *s2;
		i++;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
