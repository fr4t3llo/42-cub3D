/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/15 19:12:26 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int ft_check_content(t_map *map)
{
	int i;
	int j;
	int idx;
	i = 0;
	idx = 0;
	while (map->map2d[i])
	{
		j = 0;
		while (map->map2d[i][j])
		{
			if (ft_strchr("NSWE", map->map2d[i][j]))
				idx++;
			j++;
		}	
		i++;
	}
	if (idx > 1 || idx == 0)
		return (1);
	return (0);
}

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
}
void	draw_map(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
	{
		printf("error\n");
		exit(1);
	}
	int i = 0;
	int j;
	int x = 0;
	int y = 0;
	map->mlx_win = mlx_new_window(map->mlx_ptr, 1950, 1108, "FRATELLO CUB3D");
	map->mlx_red = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/red.xpm" , &map->width, &map->height);
	map->mlx_chibi = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/chibi.xpm" , &map->width, &map->height);
	// map->mlx_rose = mlx_xpm_file_to_image(map->mlx_ptr, "rose.xpm" , &map->width, &map->height);
	map->mlx_jnbfo9 = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/jenb-fo9.xpm", &map->width, &map->height);
	map->mlx_jnbte7t = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/jenbte7t.xpm", &map->width, &map->height);
	map->mlx_rightte7t = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/right-te7t.xpm", &map->width, &map->height);
	map->mlx_rightfo9 = mlx_xpm_file_to_image(map->mlx_ptr, "xpmfile/rightfo9.xpm", &map->width, &map->height);
	while (map->map2d[i])
	{
		j = 0;
		while (map->map2d[i][j])
		{
			if (map->map2d[i][j] == '1')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_red, x, y);
			}
			else if (map->map2d[i][j] == '0')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_chibi, x, y);
			}
			else if (map->map2d[i][j] == '7')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_jnbfo9, x, y);
			}
			else if (map->map2d[i][j] == '2')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_jnbte7t, x, y);
			}
			else if (map->map2d[i][j] == '3')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_rightte7t, x, y);
			}
			else if (map->map2d[i][j] == '9')
			{
				mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_rightfo9, x, y);
			}
			// {
			// 	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_rose, x, y);
			// }
			x += 65;
			j++;
		}
		y += 65;
		x = 0;
		i++;
	}
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
	retrun_map_2d(&map);
	// if (ft_check_all_map(map.map2d) == 1 || ft_check_content(&map) == 1 || ft_check_horizontal(&map) == 1 || ft_check_vertical(&map) == 1)
	// {
	// 	printf("error walls\n");
	// 	exit(EXIT_FAILURE);
	// }
	ft_check_line_before_map(map.map2d, &map);
	ft_check_map_len(&map);
	// draw_map(&map);
	// mlx_loop(map.mlx_ptr);
	return (0);
}
