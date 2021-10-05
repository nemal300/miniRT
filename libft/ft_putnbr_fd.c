/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:22:19 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:16:22 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilen(int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ssize(int n)
{
	int size;
	int len;

	len = ilen(n) - 1;
	size = 1;
	while (len--)
		size *= 10;
	return (size);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		size;
	char	c;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	size = ssize(n);
	if (n < 0)
		write(fd, "-", 1);
	while (size > 0)
	{
		c = n / size;
		if (n < 0)
			c *= -1;
		c += '0';
		write(fd, &c, 1);
		n = n - n / size * size;
		size /= 10;
	}
}
