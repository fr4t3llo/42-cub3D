/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/31 18:13:59 by skasmi           ###   ########.fr       */
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

void	ft_read_map(char **av)
{
	int fd;
	char *tab = NULL;
	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("\033[0;31mfile not found !!\n");
		exit(1);		
	}
	tab = (char *)malloc(sizeof(char *) * 100);
	if (!tab)
		return;
	// tab = get_next_line(fd);
	// printf("%s\n", tab);
}

int	main(int ac, char **av)
{
	//t_map	*t;
	
	//t = NULL;
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
	ft_read_map(av);
	return (0);
}
