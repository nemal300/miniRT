/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:06:33 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 21:41:14 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	str_len(char *s)
{
	int ret;

	ret = 0;
	if (!s)
		return (0);
	while (s[ret] != '\0')
		ret++;
	return (ret);
}

char		*str_join(char *temp, char *buf)
{
	char	*ret;
	int		len1;
	int		len2;

	if (!temp && !buf)
		return (0);
	len1 = str_len(temp);
	len2 = str_len(buf);
	if (!(ret = (char *)malloc((sizeof(char) * (len1 + len2 + 1)))))
		return (0);
	ret[len2 + len1] = '\0';
	while (len2--)
		ret[len1 + len2] = buf[len2];
	while (len1--)
		ret[len1] = temp[len1];
	free(temp);
	return (ret);
}

static int	sizen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

char		*str_sub(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (sizen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*str_rem(char *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (!(ret = (char *)malloc(sizeof(char) * ((str_len(s) - sizen(s))))))
		return (NULL);
	i++;
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	free(s);
	return (ret);
}
