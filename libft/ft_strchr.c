/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:02:32 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/31 17:21:28 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	if (c == 0)
	{
		return (s + ft_strlen(s));
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		else
			i++;
	}
	return (NULL);
}
