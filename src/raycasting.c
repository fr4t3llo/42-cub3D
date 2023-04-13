/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:21:10 by aelyakou          #+#    #+#             */
/*   Updated: 2023/02/09 20:06:33 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	get_dir_h(double ra)
{
	int	res;

	res = 0;
	if (ra == 90 || ra == 270)
		return (res);
	if (ra > 90 && ra < 270)
		return (res = -1, res);
	if (ra < 90 || ra > 270)
		res = 1;
	return (res);
}

double	get_hwy(t_data *data, int dir)
{
	int	wy;

	if (dir == -1)
	{
		wy = (floor(data->ply->p_pos->y / UNIT) * UNIT);
	}
	if (dir == 1)
	{
		wy = (floor(data->ply->p_pos->y / UNIT) * UNIT) + UNIT;
	}
	return (wy);
}

int	check_bounds_h(t_data *data, t_pos *wpos, double xa, double ya)
{
	if ((int)(wpos->x / UNIT) >= data->lvl->width_only_map || (int)(wpos->x
			/ UNIT) <= 0)
		return (1);
	while (data->lvl->only_map[(int)(wpos->y / UNIT)][(int)(wpos->x
			/ UNIT)] != '1')
	{
		wpos->x += xa;
		wpos->y += ya;
		if ((int)(wpos->x / UNIT) >= data->lvl->width_only_map || (int)(wpos->x
				/ UNIT) <= 0)
			return (0);
	}
	return (0);
}

t_pos	check_wall_h(double *res, double ra, t_data *data)
{
	double	xa;
	double	ya;
	int		dir;
	t_pos	wpos;

	wpos.x = 0;
	wpos.y = 0;
	*res = 0;
	dir = get_dir_v(ra);
	if (dir == 0)
		return (*res = INFINITY, wpos);
	ya = UNIT * dir;
	xa = ya / -tanf(deg_to_rad(ra));
	wpos.y = get_hwy(data, dir);
	wpos.x = data->ply->p_pos->x + ((data->ply->p_pos->y - wpos.y)
			/ tanf(deg_to_rad(ra)));
	if (dir == -1)
		wpos.y -= 1;
	if (check_bounds_h(data, &wpos, xa, ya))
		return (*res = INFINITY, wpos);
	*res = sqrtf(powf((data->ply->p_pos->x - wpos.x), 2)
			+ powf((data->ply->p_pos->y - wpos.y), 2));
	return (wpos);
}

double	cast_ray(t_data *data, int i, double ra)
{
	double	h;
	double	v;
	t_pos	wposv;
	t_pos	wposh;

	data->rays[i].ra = ra;
	h = INFINITY;
	v = INFINITY;
	wposv = check_wall_v(&v, ra, data);
	wposh = check_wall_h(&h, ra, data);
	if (h >= v)
	{
		data->rays[i].is_v = 1;
		data->rays[i].wall_pos = wposv;
		return (normalize_ray(v, ra, data));
	}
	if (h < v)
	{
		data->rays[i].wall_pos = wposh;
		return (normalize_ray(h, ra, data));
	}
	return (INFINITY);
}
