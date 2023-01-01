/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/01 16:15:35 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void ft_check_line_before_map(char **map2d, t_map *map)
{
	int i;
	char *line;
	
	i = 0;
	while (map2d[i])
	{
		line = ft_strtrim(map2d[i], " \n");
		if (map2d[0])
		{
			free(line);
			break;
		}
		check_line_txt_rgb(line, map);
		// free 
	}
	// check if exist;	
}

void	ft_check_color(char *line, t_map *map)
{
	
}

void	ft_check_txt(char *line, char *test, t_map *map)
{
	
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
// void ft_add_to_list(t_map *map)
// {
//     int k = 0;
// 	char *str = NULL;
// 	char **split;
// 	while (map->map2d[k])
// 	{
// 		str = ft_strjoin(str, map->map2d[k]);
// 		k++;
// 	}
// 	split = ft_split(str, '\n');
// 	int i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }