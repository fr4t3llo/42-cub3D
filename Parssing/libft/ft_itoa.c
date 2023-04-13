/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:25:28 by skasmi            #+#    #+#             */
/*   Updated: 2021/11/25 18:22:29 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_counter(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	size_t	k;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	k = ft_counter(n);
	tmp = malloc(sizeof(char) * (k + 1));
	if (!tmp)
		return (NULL);
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	tmp[k] = '\0';
	while (n > 0)
	{
		tmp[--k] = (n % 10) + 48;
		n = n / 10;
	}
	return (tmp);
}
