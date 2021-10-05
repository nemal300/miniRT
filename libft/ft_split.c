/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:22:49 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 17:07:26 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fcol(char const *s, char c)
{
	int col;

	col = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			col++;
			while (*s && *s != c)
				s++;
		}
	}
	return (col);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if ((word = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
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

char		**ft_split(char const *s, char c)
{
	int		i;
	char	**pptr;

	i = 0;
	if (!s || (pptr = (char **)malloc(sizeof(char *) * (fcol(s, c) + 1))) == 0)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			pptr[i] = get_word(s, c);
			if (pptr[i] == NULL)
			{
				cleanall(pptr);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	pptr[i] = NULL;
	return (pptr);
}
