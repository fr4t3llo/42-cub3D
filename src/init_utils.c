/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:56:09 by aelyakou          #+#    #+#             */
/*   Updated: 2023/02/10 05:10:16 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_init_data(t_data **data, t_map *map)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		exit(1);
	(*data)->lvl = map;
	(*data)->mlx = malloc(sizeof(t_mlx));
	if (!(*data)->mlx)
		exit(1);
	(*data)->ply = malloc(sizeof(t_ply));
	if (!(*data)->ply)
		exit(1);
	(*data)->wrld = malloc(sizeof(t_img));
	if (!(*data)->wrld)
		exit(1);
}
