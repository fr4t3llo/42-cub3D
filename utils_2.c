/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/15 22:56:31 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **ft_check_map_len(t_map *t)
{
	int nb;
	int index;
	char **map;
	int i;

	i = 0;
	map = NULL;
	nb = ft_get_len_ofmap(t->map2d) - t->line_empty - 6;
	index = t->map_height - nb;
	while (index != t->map_height)
	{
		printf("%s\n", map[i]);
		printf("im here\n");
		map[i] = ft_strjoin(map[i], t->map2d[index]);
		index++;
		i++;
	}
	return (map);
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

void ft_check_line_before_map(char **str, t_map *map)
{
	int i;
	char *line;
	
	i = 0;
	while (str[i])
	{
		line = ft_strtrim(str[i], " \n");
		if (line[0] && ft_check_line_ifnotinmap(line) == 0)
		{
			free(line);
			break;
		}
		check_line_txt_rgb(line, map);
		free(line);
		i++;
	}
	// check if exist;	
}

int ft_check_number_of_comma(char *str)
{
	int i;
	int nb;
	
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nb++;
		i++;		
	}
	return (nb);
}

void	ft_check_color(char *line, t_map *map)
{
	(void)line;
	(void)map;
}

void	ft_check_txt(char *line, char *test, t_map *map)
{
	(void)line;
	(void)map;
	(void)test;
}
void check_line_txt_rgb(char *str, t_map *map)
{
	if (str[0] && str[0] == 'C')
		ft_check_color(str, map);
	else if (str[0] && str[0] == 'F')
		ft_check_color(str, map);
	else if (str[0] && str[0] == 'N')
		ft_check_txt(str, "NO ", map);
	else if (str[0] && str[0] == 'E')
		ft_check_txt(str, "EA ", map);
	else if (str[0] && str[0] == 'W')
		ft_check_txt(str, "WE ", map);
	else if (str[0] && str[0] == 'S')
		ft_check_txt(str, "SO ", map);
	else if (str[0])
	{
		printf("Error map !!");
		exit (1);
	}
	else
		ft_count(map);
}

void ft_count(t_map *map)
{
	map->line_empty++;
}