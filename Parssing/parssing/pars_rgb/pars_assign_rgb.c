/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_assign_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:27:52 by skasmi            #+#    #+#             */
/*   Updated: 2023/02/10 03:58:48 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_assign_frgb(char **rgb, t_map *t)
{
	t->r_f = ft_atoi(rgb[0]);
	t->g_f = ft_atoi(rgb[1]);
	t->b_f = ft_atoi(rgb[2]);
}

void	ft_assign_crgb(char **rgb, t_map *t)
{
	t->r_c = ft_atoi(rgb[0]);
	t->g_c = ft_atoi(rgb[1]);
	t->b_c = ft_atoi(rgb[2]);
}
