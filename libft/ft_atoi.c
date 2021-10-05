/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:45:51 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/16 13:02:36 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int res;
	int check;

	res = 0;
	check = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
	{
		check = 1;
		str++;
	}
	else if (*str == '-')
	{
		check = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (res * 10 < res)
			return ((check < 0) ? 0 : -1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * check);
}
