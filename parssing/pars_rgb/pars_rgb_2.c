/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:23:44 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/23 00:20:50 by skasmi           ###   ########.fr       */
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

void	ft_check_txt_no(char *line, char *test, t_map *map)
{
	int		i;
	int		k;
	char	*file;
	// t_texture	t;

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
	// if (ft_check_rgb_error_c(file, t) == 1)
	// {
	// 	printf("ERROR texture\n");
	// 	exit(1);
	// }
	(void)map;
	(void)line;
	(void)map;
	(void)test;
}

void copy_texture(char *type, char *path, t_texture *t)
{
	if (type[0] == 'W')
		t->we = ft_strdup(path);
	else if (type[0] == 'E')
		t->ea = ft_strdup(path);
	else if (type[0] == 'S')
		t->so = ft_strdup(path);
	else if (type[0] == 'N')
		t->no = ft_strdup(path);
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
	if (!ft_strncmp(path, type, 3) /*|| ft_strchr(".xpm", path[])*/)
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
	t_texture t;
	
	t.ea = NULL;
	t.we = NULL;
	t.so = NULL;
	t.no = NULL;
	if (str[0] && str[0] == 'C')
		ft_check_color2(str);
	else if (str[0] && str[0] == 'F')
		ft_check_color(str);
	else if (str[0] && str[0] == 'S')
		ft_check_txt(str, "SO ", &t);
	else if (str[0] && str[0] == 'N')
		ft_check_txt(str, "NO ", &t);
	else if (str[0] && str[0] == 'E')
		ft_check_txt(str, "EA ", &t);
	else if (str[0] && str[0] == 'W')
		ft_check_txt(str, "WE ", &t);
	else if (str[0])
	{
		printf("Error map !!");
		exit(1);
	}
	else
		map->line_empty++;
}
