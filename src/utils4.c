/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 01:35:10 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 01:35:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	keydown(int keycode, t_data *data)
{
	get_m_dir(keycode, data);
	get_r_dir(keycode, data);
	if (keycode == 53)
		ft_quit(data);
	return (keycode);
}

void	is_collided(double x, double y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = x / UNIT;
	map_y = y / UNIT;
	if (data->lvl->only_map[map_y][map_x]
		&& data->lvl->only_map[map_y][map_x] == '1')
		return ;
	if (data->lvl->only_map[map_y][(int)data->ply->p_pos->x / UNIT] == '1'
			&& data->lvl->only_map[(int)data->ply->p_pos->y
				/ UNIT][map_x] == '1')
		return ;
	else
	{
		data->ply->p_pos->x = x;
		data->ply->p_pos->y = y;
	}
	return ;
}
