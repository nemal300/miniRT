/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:48 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 13:25:24 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	ft_lstadd_back_cam(t_camera **camera, t_camera *newcamera)
{
	t_camera	*temp;

	if (!*camera)
	{
		*camera = newcamera;
		return ;
	}
	temp = *camera;
	while (temp->next)
		temp = temp->next;
	temp->next = newcamera;
	return ;
}

void	ft_lstadd_back_light(t_light **light, t_light *newlight)
{
	t_light	*temp;

	if (!*light)
	{
		*light = newlight;
		return ;
	}
	temp = *light;
	while (temp->next)
		temp = temp->next;
	temp->next = newlight;
	return ;
}

void	ft_lstadd_back_obj(t_obj **obj, t_obj *newobj)
{
	t_obj *temp;

	if (!*obj)
	{
		*obj = newobj;
		return ;
	}
	temp = *obj;
	while (temp->next)
		temp = temp->next;
	temp->next = newobj;
	return ;
}

void	ft_lstadd_front_obj(t_obj **obj, t_obj *newobj)
{
	if (newobj)
	{
		newobj->next = *obj;
		*obj = newobj;
	}
}
