/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:03:59 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:26:52 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char *res;

	res = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			res = (char *)s;
			return (res);
		}
		s++;
	}
	if (c == '\0')
	{
		res = (char *)s;
		return (res);
	}
	return (res);
}
