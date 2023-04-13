/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 06:07:37 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_content(t_map *map)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (map->only_map[i])
	{
		j = 0;
		while (map->only_map[i][j])
		{
			if (ft_strchr("NSWE", map->only_map[i][j]))
				idx++;
			j++;
		}
		i++;
	}
	if (idx != 1)
		return (1);
	return (0);
}

int	ft_check_map_one(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[j])
		{
			if (tab[i][j] != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_file_map(char **map)
{
	int	i;

	i = 0;
	while (map[1][i])
		i++;
	if (map[1][i - 1] == 'b' && map[1][i - 2] == 'u' && map[1][i - 3] == 'c'
		&& map[1][i - 4] == '.')
		return (0);
	else
		return (1);
}

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') && str[i + 1] != '\0')
		{
			i++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_export_only_map2d(t_map *t)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (check_empty_line(t->export_only_map) == 1)
	{
		printf("Error\nmap error\n");
		free(t->export_only_map);
		exit(1);
	}
	t->only_map = ft_split(t->export_only_map, '\n');
	free(t->export_only_map);
	return (0);
}
