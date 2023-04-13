/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:18:18 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 09:18:17 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_quit(t_data *data)
{
	mlx_destroy_image(data->mlx->mp, data->wrld->img);
	mlx_destroy_image(data->mlx->mp, data->we);
	mlx_destroy_image(data->mlx->mp, data->so);
	mlx_destroy_image(data->mlx->mp, data->no);
	mlx_destroy_image(data->mlx->mp, data->ea);
	mlx_destroy_window(data->mlx->mp, data->mlx->w3);
	ft_free(data->lvl->only_map);
	free(data->ply->p_pos);
	free(data->ply);
	free(data->mlx);
	free(data->wrld);
	free(data);
	exit(0);
	return (0);
}

char	assign_ray_orient(double ra, int is_v)
{
	if (is_v)
	{
		if (get_dir_h(ra) == 1)
			return ('E');
		else
			return ('W');
	}
	else
	{
		if (get_dir_v(ra) == 1)
			return ('S');
		else
			return ('N');
	}
}

void	loop_rays(t_data *data)
{
	int		i;
	double	ra;
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), data->mlx->w_w - 1);
	data->rays = ray;
	if (!data->rays)
		return ;
	i = data->mlx->w_w - 1;
	while (i >= 0)
	{
		ra = (data->ply->pa + 30.0) - ((double)(i)*data->abr);
		ra = limit_angles(ra);
		data->rays[i].dist = cast_ray(data, i, ra);
		data->rays[i].orient = assign_ray_orient(ra, data->rays[i].is_v);
		i--;
	}
}

void	render_sky(t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->mlx->w_h / 2)
	{
		x = 0;
		while (x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, data->lvl->cl_c);
			x++;
		}
		y++;
	}
}

void	render_floor(t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = data->mlx->w_h / 2;
	while (y < data->mlx->w_h)
	{
		x = 0;
		while (x < data->mlx->w_w)
		{
			pixel_put_img(img, x, y, data->lvl->fl_c);
			x++;
		}
		y++;
	}
}
