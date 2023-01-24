/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:09 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/23 22:27:20 by skasmi           ###   ########.fr       */
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

int	ft_check_rgb_error_f(char *line, t_rgb t)
{
	char	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2 && ft_check_line_rgb(line) == 0)
	{
		line = ft_strcpy(line, line);
		rgb = ft_split(line, ',');
		if (check(rgb[0]) == 0 && check(rgb[1]) == 0 && check(rgb[2]) == 0)
		{
			t.r_F = ft_atoi(rgb[0]);
			t.g_F = ft_atoi(rgb[1]);
			t.b_F = ft_atoi(rgb[2]);
		}
		else
		{
			ft_free(rgb);
			return (1);
		}
		ft_free(rgb);
		if ((t.r_F >= 0 && t.r_F <= 255) && (t.g_F >= 0 && t.g_F <= 255)
			&& (t.b_F >= 0 && t.b_F <= 255))
			return (0);
	}
	return (1);
}

int	ft_check_rgb_error_c(char *line, t_rgb t)
{
	char	**rgb;
	int		i;

	i = 0;
	if (ft_check_number_of_comma(line) == 2 && ft_check_line_rgb(line) == 0)
	{
		line = ft_strcpy(line, line);
		rgb = ft_split(line, ',');
		if (check(rgb[0]) == 0 && check(rgb[1]) == 0 && check(rgb[2]) == 0)
		{
			t.r_C = ft_atoi(rgb[0]);
			t.g_C = ft_atoi(rgb[1]);
			t.b_C = ft_atoi(rgb[2]);
		}
		else
		{
			ft_free(rgb);
			return (1);
		}
		ft_free(rgb);
		if ((t.r_C >= 0 && t.r_C <= 255) && (t.g_C >= 0 && t.g_C <= 255)
			&& (t.b_C >= 0 && t.b_C <= 255))
			return (0);
	}
	return (1);
}

void	ft_check_color2(char *line)
{
	char	*file;
	t_rgb	t;

	ft_memset(&t, 0, sizeof(t));
	file = ft_strdup(line);
	if (ft_check_rgb_error_c(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
}

void	ft_check_color(char *line)
{
	char	*file;
	t_rgb	t;

	ft_memset(&t, 0, sizeof(t));
	file = ft_strdup(line);
	if (ft_check_rgb_error_f(file, t) == 1)
	{
		printf("ERROR rgb color\n");
		exit(1);
	}
}
