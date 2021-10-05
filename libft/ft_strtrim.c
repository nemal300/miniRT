/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:42:00 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:22:43 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char c, const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		l;
	int		r;
	int		i;

	if (!s1)
		return (NULL);
	l = 0;
	i = 0;
	r = ft_strlen(s1) - 1;
	while (check(s1[l], set))
		l++;
	while (check(s1[r], set) && r > l)
		r--;
	if ((ptr = malloc(r - l + 2)) == 0)
		return (NULL);
	ptr[i] = s1[l];
	while (l <= r)
	{
		i++;
		l++;
		ptr[i] = s1[l];
	}
	ptr[i] = '\0';
	return (ptr);
}
