/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:51 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:39:03 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if ((!(ft_isalpha(s[i])) && !(ft_isdigit(s[i]))
		&& ft_isspacew(s[i]) && s[i] != '-' && s[i] != '.' && s[i] != ',') == 1)
			return (0);
		i++;
	}
	return (1);
}

int	count_words(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] != '\n' && ft_isspacew(line[i]))
			i++;
		if (line[i] && line[i] != '\n')
			count++;
		while (line[i] && line[i] != '\n' && !ft_isspacew(line[i]))
			i++;
	}
	return (count);
}
