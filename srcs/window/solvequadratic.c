/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvequadratic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:23 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 14:33:16 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			get_sol(t_vec coef, double *t0, double *t1)
{
	*t0 = -0.5 * coef.y / coef.x;
	*t1 = *t0;
	return (0);
}

double		solvequadratic(t_vec coef, double *t0, double *t1)
{
	double d;
	double q;
	double temp;

	d = (coef.y * coef.y) - (4 * coef.x * coef.z);
	if (d < 0)
		return (-1);
	if (d == 0)
		return (get_sol(coef, t0, t1));
	if (coef.y > 0)
		q = -0.5 * (coef.y + sqrtf(d));
	else
		q = -0.5 * (coef.y - sqrtf(d));
	*t0 = q / coef.x;
	*t1 = coef.z / q;
	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (0);
}
