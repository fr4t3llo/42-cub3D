/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_adds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:47:49 by aelyakou          #+#    #+#             */
/*   Updated: 2023/02/09 01:31:40 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	pixel_put_img(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if ((x >= 0 && x < (P_W * SSCL)) && (y >= 0 && y < P_H * SSCL))
	{
		dst = img->addr + (y * img->len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	mlx_get_color_at(void *img, int x, int y, unsigned int *color)
{
	char	*data_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	data_ptr = (char *)mlx_get_data_addr(img, &bits_per_pixel,
			&size_line, &endian);
	*color = *(unsigned int *)(data_ptr + (y * size_line)
			+ (x * (bits_per_pixel / 8)));
}
