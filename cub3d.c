/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/11/05 22:37:28 by skasmi           ###   ########.fr       */
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

// void	ft_read_map(t_map *t, char **av)
// {
// 	t->fd = open(av[1], O_RDONLY);
// 	if (t->fd < 0)
// 	{
// 		printf("\033[0;31mfile not found !!\n");
// 		exit(1);
// 	}
// 	t->tab = get_next_line(t->fd);
// 	while (t->tab)
// 	{
// 		free(t->tab);
// 		t->tab = get_next_line(t->fd);
// 		t->i++;
// 	}
// 	t->str = (char **)malloc((t->i + 1) * sizeof(char *));
// 	if (!t->str)
// 		return ;
// 	t->j = 0;
// 	close(t->fd);
// 	t->fd = open(av[1], O_RDONLY);
// 	t->str[t->j] = get_next_line(t->fd);
// 	while (t->j < t->i)
// 	{
// 		t->j++;
// 		t->str[t->j] = get_next_line(t->fd);
// 	}
// 	t->str[t->j] = NULL;
// }

void	ft_read_map(t_map *t, char **av)
{	
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
		t->i++;
	}
	t->str = (char **)malloc((t->i + 1) * sizeof(char *));
	if (!t->str)
		return ;
	t->j = 0;
	close(t->fd);
	t->fd = open(av[1], O_RDONLY);
	t->str[t->j] = get_next_line(t->fd);
	while (t->j < t->i)
	{
		t->j++;
		t->str[t->j] = get_next_line(t->fd);
	}
	t->str[t->j] = NULL;
	// return (str);
}

void ft_get_path(t_texture *t)
{
	t_map	map;
	int i;
	int j;

	i = 0;
	j = 0;
	printf("%s\n", map.str[1]);
	//  
}

int	main(int ac, char **av)
{
	t_texture t;
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
	ft_get_path(&t);
	return (0);
}
