/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:06:35 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:09:30 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_temp(char *temp)
{
	int i;

	i = 0;
	if (!temp)
		return (1);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*temp;
	char		*buf;
	int			amo;

	amo = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (check_temp(temp) && amo != 0)
	{
		if ((amo = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[amo] = '\0';
		temp = str_join(temp, buf);
	}
	free(buf);
	*line = str_sub(temp);
	temp = str_rem(temp);
	if (amo == 0)
		free(temp);
	return (amo == 0 ? 0 : 1);
}
