/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:33:03 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/23 21:40:44 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_cmplt_horz(t_map *map, int i, int j)
{
	if (j == 0 && map->only_map[i][j] != ' ')
	{
		if (map->only_map[i][j] != '1')
			return (1);
	}
	else if (j == map->width_only_map - 1)
	{
		if (map->only_map[i][j] != ' ')
			if (map->only_map[i][j] != '1')
				return (1);
	}
	else if (j != 0 && map->only_map[i][j] != ' ')
	{
		if (map->only_map[i][j - 1] == ' ' || map->only_map[i][j + 1] == ' ')
			if (map->only_map[i][j] != '1')
				return (1);
	}
	return (0);
}

int	ft_check_horizontal(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height_only_map)
	{
		j = 0;
		while (j < map->width_only_map)
		{
			if (ft_cmplt_horz(map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_cmplt_ver(t_map *map, int i, int j)
{
	if (i == 0 && map->only_map[i][j] != ' ')
	{
		if (map->only_map[i][j] != '1')
			return (1);
	}
	else if (i == map->height_only_map - 1)
	{
		if (map->only_map[i][j] != ' ')
			if (map->only_map[i][j] != '1')
				return (1);
	}
	else if (i != 0 && map->only_map[i][j] != ' ')
	{
		if (map->only_map[i - 1][j] == ' ' || map->only_map[i + 1][j] == ' ')
			if (map->only_map[i][j] != '1')
				return (1);
	}
	return (0);
}

int	ft_check_vertical(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->width_only_map)
	{
		i = 0;
		while (i < map->height_only_map)
		{
			if (ft_cmplt_ver(map, i, j) == 1)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
