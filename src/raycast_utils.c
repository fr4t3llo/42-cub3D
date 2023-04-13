/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:36:01 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/09 02:04:05 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	get_dir_v(double ra)
{
	int	res;

	res = 0;
	if (ra == 0)
		return (res);
	if (ra > 180)
		res = 1;
	else if (ra < 180)
		res = -1;
	return (res);
}

double	get_vwx(t_data *data, int dir)
{
	double	wx;

	if (dir == -1)
	{
		wx = ((int)(data->ply->p_pos->x / UNIT) * UNIT);
	}
	if (dir == 1)
	{
		wx = ((int)(data->ply->p_pos->x / UNIT) * UNIT) + UNIT;
	}
	return (wx);
}

int	check_bounds(t_data *data, t_pos *wpos, double xa, double ya)
{
	if ((int)(wpos->y / UNIT) >= data->lvl->height_only_map || (int)(wpos->y
			/ UNIT) <= 0)
		return (1);
	while (data->lvl->only_map[(int)floor(wpos->y / UNIT)][(int)floor(wpos->x
			/ UNIT)] != '1')
	{
		wpos->x += xa;
		wpos->y += ya;
		if ((int)(wpos->y / UNIT) >= data->lvl->height_only_map || (int)(wpos->y
				/ UNIT) <= 0)
			return (1);
	}
	return (0);
}

t_pos	check_wall_v(double *res, double ra, t_data *data)
{
	double	xa;
	double	ya;
	int		dir;
	t_pos	wpos;

	wpos.x = 0;
	wpos.y = 0;
	*res = 0;
	dir = get_dir_h(ra);
	if (dir == 0)
		return (*res = INFINITY, wpos);
	xa = UNIT * dir;
	ya = xa * -tanf(deg_to_rad(ra));
	wpos.x = get_vwx(data, dir);
	wpos.y = data->ply->p_pos->y + ((data->ply->p_pos->x - wpos.x)
			* tanf(deg_to_rad(ra)));
	if (dir == -1)
		wpos.x -= 1;
	if (check_bounds(data, &wpos, xa, ya))
		return (*res = INFINITY, wpos);
	*res = sqrtf(powf((data->ply->p_pos->x - wpos.x), 2)
			+ powf((data->ply->p_pos->y - wpos.y), 2));
	return (wpos);
}
