/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:54:59 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:13:51 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_isspacew(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	fcol(char const *s)
{
	int col;

	col = 0;
	while (*s)
	{
		while (*s && ft_isspacew(*s))
			s++;
		if (*s && !ft_isspacew(*s))
		{
			col++;
			while (*s && !ft_isspacew(*s))
				s++;
		}
	}
	return (col);
}

static char	*get_word(char const *s)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && !ft_isspacew(s[i]))
		i++;
	if ((word = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	i = 0;
	while (s[i] && !ft_isspacew(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	cleanall(char **pptr)
{
	free(pptr);
}

char		**ft_splitf(char const *s)
{
	int		i;
	char	**pptr;

	i = 0;
	if (!s || (pptr = (char **)malloc(sizeof(char *) * (fcol(s) + 1))) == 0)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspacew(*s))
			s++;
		if (*s && !ft_isspacew(*s))
		{
			pptr[i] = get_word(s);
			if (pptr[i] == NULL)
			{
				cleanall(pptr);
				return (NULL);
			}
			i++;
			while (*s && !ft_isspacew(*s))
				s++;
		}
	}
	pptr[i] = NULL;
	return (pptr);
}
