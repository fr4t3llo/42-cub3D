/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:07:01 by skasmi            #+#    #+#             */
/*   Updated: 2022/12/21 00:19:31 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int ft_check_err(char **str, int i, int j)
// {
//     if (str[i][j + 1] != '1' && str[i][j + 1] != '0'
//         	&& !ft_strchr("SWEN", str[i][j + 1]))
//         return (1);
// 	if (str[i][j - 1] != '1' && str[i][j - 1] != '0'
// 			&& !ft_strchr("SEWN", str[i][j - 1]))
// 		return (1);
// 	if (str[i + 1][j] != '1' && str[i + 1][j] != '0'
// 			&& !ft_strchr("SEWN", str[i + 1][j]))
// 		return (1);
// 	if (str[i - 1][j] != '1' && str[i - 1][j] != '0'
// 			&& !ft_strchr("SEWN", str[i - 1][j]))
// 		return (1);
//     if (!str[i][j + 1])
// 		return (1);
// 	if (!str[i][j - 1])
// 		return (1);
// 	if (!str[i + 1][j])
// 		return (1);
// 	if (!str[i - 1][j])
// 		return (1);
// 	return (0);
// }

int ft_get_len_ofmap(char **str)
{
	int i;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int get_len(char **str)
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

char **retrun_map_2d(char **map)
{
	int i;
	int j;
	int k;
	int nb;
	char **str;
	nb = 0;
	k = 0;
	i = get_len(map);
	j = ft_get_len_ofmap(map);
	
	
	while (j > 0)
	{
		if (ft_strlen(map[k]) < i)
			while ( != i)
			{
				map[k] = ft_strjoin(map[k], ' ');

			} 
	}
}

