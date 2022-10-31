/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:04:26 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/31 17:17:03 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_rest(char *st)
{
	int	i;
	int	k;
	char	*rest;

	i = 0;
	while (st[i] != '\n' && st[i])
		i++;
	if (ft_strlen(st) == i)
	{
		free(st);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(st) - i + 1));
	if (!rest)
		return (NULL);
	k = 0;
	while (st[i++])
	{
		rest[k] = st[i];
		k++;
	}
	rest[k] = '\0';
	free(st);
	return (rest);
}

char	*ft_line(char *str)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_read(char *str, int fd)
{
	char	*buff;
	int		s1;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	s1 = 1;
	while (!ft_strchr(str, '\n') && s1 != 0)
	{
		s1 = read(fd, buff, BUFFER_SIZE);
		if (s1 == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[s1] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (str == NULL )
		return (NULL);
	line = ft_line(str);
	str = ft_rest(str);
	return (line);
}
