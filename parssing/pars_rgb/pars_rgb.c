/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/17 23:44:24 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_rgb_error_f(char *line, t_rgb t)
{
	char	**rgb;
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

int	ft_check_rgb_error_c(char *line, t_rgb t)
{
	char	**rgb;
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
	int		i;
	int		k;
	char	*file;
	t_rgb	t;

	t.b_F = 0;
	file = (char *)malloc(sizeof(char) * ft_strlen(line) - 1);
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
	if (ft_check_rgb_error_c(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
	(void)map;
}

void	ft_check_color(char *line, t_map *map)
{
	int		i;
	int		k;
	char	*file;
	t_rgb	t;

	t.b_F = 0;
	file = (char *)malloc(sizeof(char) * ft_strlen(line) - 1);
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
	if (ft_check_rgb_error_f(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
	(void)map;
}
