/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:20:35 by aelyakou          #+#    #+#             */
/*   Updated: 2023/02/08 19:06:36 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

double	rad_to_deg(double x)
{
	double	res;

	res = x * 180 / PI;
	return (res);
}

double	deg_to_rad(double x)
{
	double	res;

	res = x * PI / 180;
	return (res);
}

double	normalize_ray(double rl, double ra, t_data *data)
{
	double	res;
	double	rpa;

	if (ra < data->ply->pa)
		rpa = data->ply->pa - ra;
	else
		rpa = ra - data->ply->pa;
	res = rl * cos(deg_to_rad(rpa));
	return (res);
}
