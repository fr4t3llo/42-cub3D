/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/30 19:38:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file_map(char *map)
{
	int	i;
	
	i = ft_strlen(map) - 1;
	if (map[i] == 'b')
	{
		i--;
		if (map[i] == 'u')
		{
			i--;
			if (map[i] == 'c')
			{
				i--;
				if (map[i] == '.')
					return (0);
			}
		}
	}
	return (1);
	
}
int	main(int ac, char **av)
{
	int fd;
    if (ac == 2)
    {
		fd = open(av[1], O_RDWR);
		if (fd < 0)
			printf("\033[0;31mfile not found !!\n");
		else if (ft_check_file_map(av[1]) == 1)
			printf("Error Map Extention !!\n");
    }
	return (0);
}