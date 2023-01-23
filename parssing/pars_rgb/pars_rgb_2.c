/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:23:44 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/23 09:06:16 by skasmi           ###   ########.fr       */
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

void copy_texture(char *type, char *path, t_texture *t)
{
	if (type[0] == 'W')
	{	
		if (t->we == NULL)
			t->we = ft_strdup(path);
		else
		{
			printf("6ERROR texture\n");
			exit (1);
		}
	}
	else if (type[0] == 'E')
	{	
		if (t->ea == NULL)
			t->ea = ft_strdup(path);
		else 
		{
			printf("6ERROR texture\n");
			exit (1);
		}

	}	
	else if (type[0] == 'S')
	{	
		if (t->so == NULL)
			t->so = ft_strdup(path);
		else
		{
			printf("0ERROR texture\n");
			exit (1);
		}
		
	}
	else if (type[0] == 'N')
	{	
		if (t->no == NULL)
			t->no = ft_strdup(path);
		else 
		{
			printf("*ERROR texture\n");
			exit (1);
		}
	}
	else 
	{
		printf("Error texture\n");
		exit (1);
	}
}



void ft_check_txt(char *path, char *type, t_texture *t)
{
	int fd;
	int i;
	int len;
	len = ft_strlen(path);
	i = 0;
	char **str = ft_split(path, ' ');
	if (!ft_strncmp(path, type, 3))
	{
		fd = open(str[1], O_RDWR);
		if (fd < 0)
		{
			printf("Error texture\n");
			exit (1);
		}
		close(fd);
		copy_texture(&type[0], str[1], t);
	}
	
}

void	check_line_txt_rgb(char *str, t_map *map)
{
	if (str[0] && str[0] == 'C')
		ft_check_color2(str);
	else if (str[0] && str[0] == 'F')
		ft_check_color(str);
	else if (str[0] && str[0] == 'S')
		ft_check_txt(str, "SO ", map->t);
	else if (str[0] && str[0] == 'N')
		ft_check_txt(str, "NO ", map->t);
	else if (str[0] && str[0] == 'E')
		ft_check_txt(str, "EA ", map->t);
	else if (str[0] && str[0] == 'W')
		ft_check_txt(str, "WE ", map->t);
	else if (str[0])
	{
		printf("Error map !!");
		exit(1);
	}
	else
		map->line_empty++;
}
