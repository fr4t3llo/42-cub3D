/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/21 00:37:33 by skasmi           ###   ########.fr       */
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
	while (map->only_map[i])
	{
		j = 0;
		while (map->only_map[i][j])
		{
			if (ft_strchr("NSWE", map->only_map[i][j]))
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
	t->all_map2d = (char **)malloc((i + 1) * sizeof(char *));
	if (!t->all_map2d)
		return ;
	j = 0;
	close(t->fd);
	t->fd = open(av[1], O_RDONLY);
	t->all_map2d[j] = get_next_line(t->fd);
	while (j < i)
	{
		j++;
		t->all_map2d[j] = get_next_line(t->fd);
	}
	t->all_map2d[j] = NULL;
}

int check_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!str[i + 1])
			if (str[i] == '\n' && str[i + 1] == '\n')
				return (1);
		i++;
	}
	printf("hello \n");
	return (0);	
}

int ft_export_only_map2d(t_map *t)
{
	char *str;
	char *check;
	int i;

	str = NULL;
	i = 0;
	if (check_empty_line(t->export_only_map) == 0)
	{	
		t->only_map = ft_split(t->export_only_map, '\n');
		
		while (t->only_map[i])
		{
			str = ft_strjoin(str, t->only_map[i]);
			check = ft_strtrim(str, " \t\n");
			if (check[0] == '\0')
				return (1);
			str = NULL;
			i++;
		}
	}	
	return (0);
}

int get_width(char **str)
{
	int i;
	int j;
	int len;

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

int get_height(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);	
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
	map.map_height = ft_get_len_ofmap(map.all_map2d);
	map.map_width = get_len(map.all_map2d);
	ft_check_line_before_map(map.all_map2d, &map);
	ft_check_map_len(&map);
	if (ft_export_only_map2d(&map) == 1)
	{
		printf("errooooor");
		exit(1);
	}
	printf("**************************************%s\n", map.only_map[0]);
	map.width_only_map = get_width(map.only_map);
	map.height_only_map = get_height(map.only_map);
	retrun_map_2d_withspace(&map);
	if (ft_check_all_map(map.only_map) == 1 || ft_check_content(&map) == 1 || ft_check_horizontal(&map) == 1 || ft_check_vertical(&map) == 1)
	{
		printf("error walls\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
