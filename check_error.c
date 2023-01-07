/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:07:01 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/07 19:15:32 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void ft_trim_txtr(t_map *map)
// {
// 	int i = 0;

// 	while (map->map2d[])
// }

int ft_check_horizontal(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (j == 0 && map->map2d[i][j] != ' ')
			{
				if (map->map2d[i][j] != '1')
					return (1);
			}
			else if (j == map->map_width - 1)
			{
				if (map->map2d[i][j] != ' ')
					if (map->map2d[i][j] != '1')
						return (1);
			}
			else if (j != 0 && map->map2d[i][j] != ' ')
			{
				if (map->map2d[i][j - 1] == ' ' || map->map2d[i][j + 1] == ' ')
					if (map->map2d[i][j] != '1')
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_check_vertical(t_map *map)
{
	int i;
	int j;

	j = 0;
	while (j < map->map_width)
	{
		i = 0;
		while (i < map->map_height)
		{
			if (i == 0 && map->map2d[i][j] != ' ')
			{
				if (map->map2d[i][j] != '1')
					return (1);
			}
			else if (i == map->map_height - 1)
			{
				if (map->map2d[i][j] != ' ')
					if (map->map2d[i][j] != '1')
						return (1);
			}
			else if (i != 0 && map->map2d[i][j] != ' ')
			{
				if (map->map2d[i - 1][j] == ' ' || map->map2d[i + 1][j] == ' ')
					if (map->map2d[i][j] != '1')
					{
						printf("%d   %d", i, j);
						printf("testgsdgs\n");	
						return (1);
					}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int ft_check_err(char **str, int i, int j)
{
    if (str[i][j + 1] != '1' && str[i][j + 1] != '0'
        	&& !ft_strchr("SWEN", str[i][j + 1]))
        return (1);
	if (str[i][j - 1] != '1' && str[i][j - 1] != '0'
			&& !ft_strchr("SEWN", str[i][j - 1]))
		return (1);
	if (str[i + 1][j] != '1' && str[i + 1][j] != '0'
			&& !ft_strchr("SEWN", str[i + 1][j]))
		return (1);
	if (str[i - 1][j] != '1' && str[i - 1][j] != '0'
			&& !ft_strchr("SEWN", str[i - 1][j]))
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

int ft_get_len_ofmap(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int get_len(char **str)
{
	int i;
	int j;
	int len;

	len = 0;
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (j < len)
		{
			j = len;
			i++;	
		}
		else
			i++;
	}
	return (j);
}

void retrun_map_2d(t_map *map)
{
	int k;
	int nb;
	
	k = 0;
	while (map->map_height > 0)
	{
		if (ft_strlen(map->map2d[k]) < map->map_width)
		{
			nb = ft_strlen(map->map2d[k]);
			while (nb != map->map_width)
			{
				map->map2d[k] = ft_strjoin(map->map2d[k], " ");
				nb++;
			} 
			k++;
		}
		else
			k++;
		map->map_height--;
	}
	map->map_height = ft_get_len_ofmap(map->map2d);
}

int ft_check_all_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && !ft_strchr(" SEWN", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}