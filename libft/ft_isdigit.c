/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:20:18 by kbulwer           #+#    #+#             */
/*   Updated: 2020/11/02 16:27:56 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int o)
{
	if (o >= 48 && o <= 57)
		return (1);
	else
		return (0);
}
