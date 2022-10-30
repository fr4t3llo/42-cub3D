/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:02:32 by skasmi            #+#    #+#             */
/*   Updated: 2021/11/27 21:44:39 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
