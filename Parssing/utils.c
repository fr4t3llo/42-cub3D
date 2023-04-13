/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:12:54 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 09:11:51 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_empty(t_map *t)
{
	char	**str;

	str = ft_split(*t->all_map2d, '\n');
	if (!str || str[0] == NULL)
	{
		printf("Error\n Empty map\n");
		exit(1);
	}
	ft_free(str);
}

void	ft_find_map(t_map *t, int i, char **av)
{
	int	j;

	j = 0;
	t->all_map2d = (char **)malloc((i + 1) * sizeof(char *));
	if (!t->all_map2d)
		return ;
	j = 0;
	t->fd = open(av[1], O_RDWR);
	t->all_map2d[j] = get_next_line(t->fd);
	while (j < i)
	{
		j++;
		t->all_map2d[j] = get_next_line(t->fd);
	}
	t->all_map2d[j] = NULL;
	ft_check_map_empty(t);
}

void	ft_read_map(t_map *t, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	t->fd = open(av[1], O_RDWR);
	if (t->fd < 0)
	{
		printf("\033[0;31mError\nfile not found !!\n");
		close(t->fd);
		exit(1);
	}
	t->tab = get_next_line(t->fd);
	while (t->tab)
	{
		free(t->tab);
		t->tab = get_next_line(t->fd);
		i++;
	}
	t->map_height = i;
	close(t->fd);
	ft_find_map(t, i, av);
}

int	get_width(char **str)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (j < len)
		{
			j = len;
			i++;
		}
		else
			i++;
	}
	return (j);
}

int	get_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
