/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:33:03 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/18 02:19:43 by skasmi           ###   ########.fr       */
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
	else if (j == map->map_width - 1)
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
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			ft_cmplt_horz(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_cmplt_ver(t_map *map, int i, int j)
{
	printf("ana hna \n");
	if (i == 0 && map->only_map[i][j] != ' ')
	{
		if (map->only_map[i][j] != '1')
			return (1);
	}
	else if (i == map->map_height - 1)
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
	while (j < map->map_width)
	{
		i = 0;
		while (i < map->map_height)
		{
			ft_cmplt_ver(map, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_err(char **str, int i, int j)
{
	if (str[i][j + 1] != '1' && str[i][j + 1] != '0' && !ft_strchr("SWEN",
			str[i][j + 1]))
		return (1);
	if (str[i][j - 1] != '1' && str[i][j - 1] != '0' && !ft_strchr("SEWN",
			str[i][j - 1]))
		return (1);
	if (str[i + 1][j] != '1' && str[i + 1][j] != '0' && !ft_strchr("SEWN", str[i
			+ 1][j]))
		return (1);
	if (str[i - 1][j] != '1' && str[i - 1][j] != '0' && !ft_strchr("SEWN", str[i
			- 1][j]))
		return (1);
	if (!str[i][j + 1])
		return (1);
	if (!str[i][j - 1])
		return (1);
	if (!str[i + 1][j])
		return (1);
	if (!str[i - 1][j])
		return (1);
	return (0);
}
