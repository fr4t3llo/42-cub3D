/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_rgb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:23:44 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 06:08:10 by skasmi           ###   ########.fr       */
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

void	copy_texture2(char *type, char *path, t_texture *t)
{
	if (type[0] == 'S')
	{
		if (t->so == NULL)
			t->so = ft_strdup(path);
		else
			ft_perror();
	}
	else if (type[0] == 'N')
	{
		if (t->no == NULL)
			t->no = ft_strdup(path);
		else
			ft_perror();
	}
}

void	copy_texture(char *type, char *path, t_texture *t)
{
	if (type[0] == 'W')
	{
		if (t->we == NULL)
			t->we = ft_strdup(path);
		else
			ft_perror();
	}
	else if (type[0] == 'E')
	{
		if (t->ea == NULL)
			t->ea = ft_strdup(path);
		else
			ft_perror();
	}
	else if (type[0] == 'S' || type[0] == 'N')
		copy_texture2(type, path, t);
	else
		ft_perror();
	free(path);
}

void	ft_check_txt(char *path, char *type, t_texture *t)
{
	int		fd;
	int		i;
	int		len;
	char	**str;

	len = ft_strlen(path);
	i = 0;
	str = ft_split(path, ' ');
	if (!str[1])
		ft_perror();
	if (!ft_strncmp(path, type, 3))
	{
		fd = open(str[1], O_RDWR);
		if (fd < 0)
			ft_perror();
		close(fd);
		copy_texture(&type[0], str[1], t);
	}
	free(str[0]);
	free(str);
}

void	check_line_txt_rgb(char *str, t_map *map)
{
	if (str[0] && str[0] == 'C')
	{
		ft_check_color2(str, map);
		map->check_dup++;
	}
	else if (str[0] && str[0] == 'F')
	{
		ft_check_color(str, map);
		map->check_dup++;
	}
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
		printf("Error\n map !!");
		exit(1);
	}
	else
		map->line_empty++;
}
