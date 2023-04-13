/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:07:51 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 09:11:20 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_contine_check(char *str, bool foundnum, int *i)
{
	if (foundnum == true)
	{
		while (str[(*i)])
		{
			if (str[(*i)] != ' ')
				return (1);
			(*i)++;
		}
	}
	return (0);
}

int	check(char *str)
{
	int		i;
	bool	foundnum;

	i = 0;
	foundnum = false;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			if (foundnum == false)
			{
				i++;
				continue ;
			}
			if (ft_contine_check(str, foundnum, &i) == 0)
				return (0);
			else
				return (1);
		}
		foundnum = true;
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		free(tab[j++]);
	free(tab);
}

void	ft_check_color(char *line, t_map *map)
{
	char	*file;
	int		i;

	i = 0;
	if (line[i])
	{
		if (line[i] == 'F' && line[i + 1] != ' ')
		{
			printf("Error\n rgb color\n");
			exit(1);
		}
	}
	file = ft_strdup(line);
	if (ft_check_rgb_error_f(file, map) == 1)
	{
		printf("Error\n rgb color\n");
		exit(1);
	}
	free(file);
}

void	ft_perror(void)
{
	printf("Error\n texture\n");
	exit(1);
}
