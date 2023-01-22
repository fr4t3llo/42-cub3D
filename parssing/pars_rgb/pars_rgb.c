/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/22 00:37:21 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int ft_check(char *str) {
	size_t i;
	i = 0;
	bool foundNumber = false;
	while(str[i]) {
		if (str[i] == ' ') {
			if (foundNumber == false) {
				i++;
				continue;
			}
			if (foundNumber == true) {
				while (str[i])
				{
					if (str[i] != ' ')
						return 1;
					i++;
				}
				return 0;
			}
		}
		foundNumber = true;
		if (ft_isdigit(str[i]) == 0)
			return 1;
		i++;
	}
	return 0;
}

int	ft_check_rgb_error_f(char *line, t_rgb t)
{
	char	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2)
	{
		rgb = ft_split(line, ',');
		if (ft_check(rgb[0]) == 0 && ft_check(rgb[1]) == 0 && ft_check(rgb[2]) == 0) {
		t.r_F = ft_atoi(rgb[0]);
		t.g_F = ft_atoi(rgb[1]);
		t.b_F = ft_atoi(rgb[2]);
		}
		else {
			// free2d
			return 1;
		}
		int j = 0;
		while(rgb[j])
			free(rgb[j++]);
		free(rgb);
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
		if (ft_strlen(rgb[0]) <= 3)
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
	// int		i;
	// int		k;
	char	*file;
	t_rgb	t;

	ft_memset(&t, 0, sizeof(t));
	// t.b_F = 0;
	// file = (char *)malloc(sizeof(char) * ft_strlen(line) - 1);
	// i = 1;
	// k = 0;
	// while (line[i] == ' ')
	// 	i++;
	// while (line[i])
	// {
	// 	file[k] = line[i];
	// 	i++;
	// 	k++;
	// }
	// file[k] = '\0';
	file = ft_strdup(line);
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
