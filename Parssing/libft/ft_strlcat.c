/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:06:11 by skasmi            #+#    #+#             */
/*   Updated: 2021/11/27 23:18:28 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dst[j] != '\0' && j < dstsize)
	j++;
	i = j;
	while (src[j - i] != '\0' && j + 1 < dstsize)
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < j)
		dst[j] = '\0';
	return (i + ft_strlen(src));
}
