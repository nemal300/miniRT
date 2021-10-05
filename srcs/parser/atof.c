/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:54:27 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 15:51:38 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		intlen(int n)
{
	int i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	atof;
	int		atoi;

	i = 0;
	atof = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	atoi = ft_atoi(str);
	i = intlen(atoi);
	sign == -1 ? i++ : 0;
	if (str[i] != '.')
		return (atoi);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sign *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	atof = atof / sign;
	return (atoi + atof);
}
