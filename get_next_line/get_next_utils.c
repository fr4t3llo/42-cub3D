/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:57:50 by skasmi            #+#    #+#             */
/*   Updated: 2022/11/05 20:12:08 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
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

