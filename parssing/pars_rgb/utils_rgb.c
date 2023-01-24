/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:07:51 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/24 04:37:06 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int check(char *str) 
{
	int	i;
	bool	foundNumber;
	
	i = 1;
	foundNumber = false;
	while(str[i]) 
	{
		if (str[i] == ' ') 
		{
			if (foundNumber == false)
			{
				i++;
				continue;
			}
			if (foundNumber == true) 
			{
				while (str[i])
				{
					if (str[i] != ' ')
						return 1;
					i++;
				}
				return 0;
			}
		}
		foundNumber = true;
		if (ft_isdigit(str[i]) == 0)
			return 1;
		i++;
	}
	return 0;
}

void ft_free(char **tab)
{
	int j;

	j = 0;
	while(tab[j])
		free(tab[j++]);
	free(tab);
}

