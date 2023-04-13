/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:20:52 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 06:32:42 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	diag_move(t_data *data)
{
	float	new_x;
	float	new_y;
	float	rad;

	if (data->ply->d_dir == 1)
		rad = deg_to_rad(limit_angles(data->ply->pa - 90));
	if (data->ply->d_dir == -1)
		rad = deg_to_rad(limit_angles(data->ply->pa + 90));
	new_x = data->ply->p_pos->x + cosf(rad) * MVS * data->ply->mh_dir;
	new_y = data->ply->p_pos->y - sinf(rad) * MVS * data->ply->mh_dir;
	is_collided(new_x, new_y, data);
}

void	p_move(t_data *data)
{
	float	rad;
	float	new_y;
	float	new_x;

	if (data->ply->d_dir != 0)
	{
		diag_move(data);
		return ;
	}
	rad = deg_to_rad(data->ply->pa);
	new_x = data->ply->p_pos->x + cosf(rad) * MVS * data->ply->mv_dir;
	new_y = data->ply->p_pos->y - sinf(rad) * MVS * data->ply->mv_dir;
	is_collided(new_x, new_y, data);
}

void	p_rotate(t_data *data)
{
	data->ply->pa += TRS * data->ply->r_dir;
	data->ply->pa = limit_angles(data->ply->pa);
}

void	*text_orient(t_data *data, int x)
{
	if (data->rays[x].orient == 'N')
		return (data->no);
	if (data->rays[x].orient == 'E')
		return (data->ea);
	if (data->rays[x].orient == 'S')
		return (data->so);
	if (data->rays[x].orient == 'W')
		return (data->we);
	return (NULL);
}

int	get_texel(t_data *data, int x, int y, int slice)
{
	int				text_x;
	int				text_y;
	unsigned int	color;
	void			*img;

	text_x = (int)data->rays[x].wall_pos.x % UNIT;
	img = text_orient(data, x);
	if (data->rays[x].is_v)
	{
		text_x = (int)data->rays[x].wall_pos.y % UNIT;
		text_y = ((y - ((data->mlx->w_h / 2) - (slice / 2)))
				* ((double)(double)UNIT / (double)slice));
	}
	else
	{
		text_y = ((y - ((data->mlx->w_h / 2) - (slice / 2)))
				* ((double)(double)UNIT / (double)slice));
	}
	mlx_get_color_at(img, text_x, text_y, &color);
	return (color);
}
