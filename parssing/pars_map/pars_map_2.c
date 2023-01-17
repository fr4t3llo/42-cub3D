/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:44:31 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/17 18:55:14 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


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

int ft_check_line_ifnotinmap(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}
