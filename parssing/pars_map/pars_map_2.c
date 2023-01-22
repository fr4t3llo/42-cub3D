/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:44:31 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/21 23:46:58 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int ft_get_len_ofmap(char **str) // hdra m3awda 
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
	// printf("%d\n", j);
	return (j);
}

void	retrun_map_2d_withspace(t_map *map)
{
	int k;
	int nb;
	int count;
	int count_width;
	
	count = map->height_only_map;
	count_width = map->width_only_map;
	k = 0;
	while (count > 0)
	{
		if (ft_strlen(map->only_map[k]) < count_width)
		{
			nb = ft_strlen(map->only_map[k]);
			while (nb != count_width)
			{
				map->only_map[k] = ft_strjoin(map->only_map[k], " ");
				nb++;
			}
			k++;
		}
		else 
			k++;
		count--;
	}
	map->height_only_map = ft_get_len_ofmap(map->only_map);
}

int ft_check_all_map(char **map) // khassni n3tiha ghi map 2d machi map.cub kolha
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