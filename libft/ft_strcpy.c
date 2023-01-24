/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:47:21 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/23 21:47:58 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *str, char *str2)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		str2[j] = str[i];
		j++;
		i++; 
	}
	str2[j] = '\0';
	return (str2);
}
