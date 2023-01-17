/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:23:44 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/17 18:40:12 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_number_of_comma(char *str)
{
	int	i;
	int	nb;

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

void	ft_check_txt(char *line, char *test, t_map *map)
{
	(void)line;
	(void)map;
	(void)test;
}

void	check_line_txt_rgb(char *str, t_map *map)
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
		exit(1);
	}
	else
		map->line_empty++;
}
