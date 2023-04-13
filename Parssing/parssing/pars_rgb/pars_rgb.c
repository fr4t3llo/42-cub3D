/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 09:11:28 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_line_rgb(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ' || ft_isdigit(str[i]) == 1 || str[i] == ',')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_2(char **str)
{
	char	*tmp;

	if (str[0] != NULL)
	{
		tmp = ft_strtrim(str[0], " ");
		if (ft_strlen(tmp) == 0)
			return (1);
	}
	if (str[1] != NULL)
	{
		tmp = ft_strtrim(str[1], " ");
		if (ft_strlen(tmp) == 0)
			return (1);
		free(tmp);
	}
	if (str[2] != NULL)
	{
		tmp = ft_strtrim(str[2], " ");
		if (ft_strlen(tmp) == 0)
			return (1);
		free(tmp);
	}
	return (0);
}

int	ft_check_rgb_error_f(char *line, t_map *t)
{
	char	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2 && ft_check_line_rgb(line) == 0)
	{
		line = ft_strcpy(line, line);
		rgb = ft_split(line, ',');
		free(line);
		if (!rgb[0] || !rgb[1] || !rgb[2] || ft_check_2(rgb) == 1)
			return (printf("Error\n rgb color\n"), exit(1), 0);
		if (check(rgb[0]) == 0 && check(rgb[1]) == 0 && check(rgb[2]) == 0)
			ft_assign_frgb(rgb, t);
		else
		{
			ft_free(rgb);
			return (1);
		}
		ft_free(rgb);
		if ((t->r_f >= 0 && t->r_f <= 255) && (t->g_f >= 0 && t->g_f <= 255)
			&& (t->b_f >= 0 && t->b_f <= 255))
			return (0);
	}
	return (1);
}

int	ft_check_rgb_error_c(char *line, t_map *map)
{
	char	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2 && ft_check_line_rgb(line) == 0)
	{
		line = ft_strcpy(line, line);
		rgb = ft_split(line, ',');
		free(line);
		if (!rgb[0] || !rgb[1] || !rgb[2] || (ft_check_2(rgb) == 1))
			return (printf("Error\n rgb color\n"), exit(1), 0);
		if (check(rgb[0]) == 0 && check(rgb[1]) == 0 && check(rgb[2]) == 0)
			ft_assign_crgb(rgb, map);
		else
		{
			ft_free(rgb);
			return (1);
		}
		ft_free(rgb);
		if ((map->r_c >= 0 && map->r_c <= 255) && (map->g_c >= 0
				&& map->g_c <= 255) && (map->b_c >= 0 && map->b_c <= 255))
			return (0);
	}
	return (1);
}

void	ft_check_color2(char *line, t_map *map)
{
	char	*file;
	int		i;

	i = 0;
	if (line[i])
	{
		if (line[i] == 'C' && line[i + 1] != ' ')
		{
			printf("Error\n rgb color\n");
			exit(1);
		}
	}
	file = ft_strdup(line);
	if (ft_check_rgb_error_c(file, map) == 1)
	{
		printf("Error\n rgb color\n");
		free(file);
		exit(1);
	}
	free(file);
}
