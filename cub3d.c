/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/12/22 16:44:05 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_one(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(tab[i])
	{
		while (tab[j])
		{
			if (tab[i][j] != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_file_map(char **map)
{
	int	i;

	i = 0;
	while (map[1][i])
		i++;
	if (map[1][i - 1] == 'b' && map[1][i - 2] == 'u'
		&& map[1][i - 3] == 'c' && map[1][i - 4] == '.')
		return (0);
	else
		return (1); 
	
}

void	ft_read_map(t_map *t, char **av)
{	
	int i;
	int j;

	j = 0;
	i = 0;
	t->fd = open(av[1], O_RDONLY);
	if (t->fd < 0)
	{
		printf("\033[0;31mfile not found !!\n");
		exit(1);		
	}
	t->tab = get_next_line(t->fd);
	while (t->tab)
	{
		free(t->tab);
		t->tab = get_next_line(t->fd);
		i++;
	}
	t->map2d = (char **)malloc((i + 1) * sizeof(char *));
	if (!t->map2d)
		return ;
	j = 0;
	close(t->fd);
	t->fd = open(av[1], O_RDONLY);
	t->map2d[j] = get_next_line(t->fd);
	while (j < i)
	{
		j++;
		t->map2d[j] = get_next_line(t->fd);
	}
	t->map2d[j] = NULL;
	// return (map2d);
}

int	main(int ac, char **av)
{
	t_map	map;
    if (ac != 2)
	{
		printf("Error Args !!!\n");
		exit(1); 
	}
	if (ft_check_file_map(av) == 1)
	{
		printf("\033[0;31mextention of map must finished -> .cub !!\n");
		exit(1);
	}
	ft_read_map(&map, av);
	map.map_height = ft_get_len_ofmap(map.map2d);
	map.map_width = get_len(map.map2d);
	// int k = 0;
	// while (map.map2d[k])
	// {
	// 	printf("%s\n", map.map2d[k]);
	// 	k++;
	// }
	retrun_map_2d(&map);
	if (ft_check_all_map(map.map2d) == 1 || ft_check_horizontal(&map) == 1 || ft_check_vertical(&map) == 1)
	{
		printf("error walls\n");
		exit(EXIT_FAILURE);
	}
	// ft_get_path(&map, &t);
	return (0);
}
