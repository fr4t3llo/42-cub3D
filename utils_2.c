/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/17 02:43:24 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_check_map_len(t_map *t)
{
	int nb;
	int index;
	int i;

	i = 0;
	t->export_only_map = NULL;
	nb = ft_get_len_ofmap(t->map2d) - t->line_empty - 6;
	index = t->map_height - nb;
	while (index != t->map_height)
	{
		t->export_only_map = ft_strjoin(t->export_only_map, t->map2d[index]);
		index++;
		if (index != t->map_height)
			t->export_only_map = ft_strjoin(t->export_only_map, "\n");
		i++;
	}
	// printf("%s\n", t->export_only_map);
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

int ft_check_rgb_error_f(char *line, t_rgb t)
{
	char 	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2)
	{
		rgb = ft_split(line, ',');
		t.r_F = ft_atoi(rgb[0]);
		t.g_F = ft_atoi(rgb[1]);
		t.b_F = ft_atoi(rgb[2]);
		if (t.r_F >= 0 && t.r_F <= 255)
		{
			if (t.g_F >= 0 && t.g_F <= 255)
			{
				if (t.b_F >= 0 && t.b_F <= 255)
					return (0);
			}
		}
	}
	return (1);
}

int ft_check_rgb_error_c(char *line, t_rgb t)
{
	char 	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2)
	{
		rgb = ft_split(line, ',');
		t.r_C = ft_atoi(rgb[0]);
		t.g_C = ft_atoi(rgb[1]);
		t.b_C = ft_atoi(rgb[2]);
		if (t.r_C >= 0 && t.r_C <= 255)
		{
			if (t.g_C >= 0 && t.g_C <= 255)
			{
				if (t.b_C >= 0 && t.b_C <= 255)
					return (0);
			}
		}
	}
	return (1);
}

void	ft_check_color2(char *line, t_map *map)
{
	int i;
	int k;
	char *file;
	t_rgb t;

	t.b_F = 0;
	file = (char*)malloc(sizeof(char) * ft_strlen(line) - 1);
	i = 1;
	k = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		file[k] = line[i];
		i++;
		k++;
	}
	file[k] = '\0';	
	if(ft_check_rgb_error_c(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
	(void)map;
}

void	ft_check_color(char *line, t_map *map)
{
	int i;
	int k;
	char *file;
	t_rgb t;

	t.b_F = 0;
	file = (char*)malloc(sizeof(char) * ft_strlen(line) - 1);
	i = 1;
	k = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		file[k] = line[i];
		i++;
		k++;
	}
	file[k] = '\0';	
	if(ft_check_rgb_error_f(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
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
		ft_check_color2(str, map);
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