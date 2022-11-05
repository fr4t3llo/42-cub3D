#include "../cub3d.h"

// char	*get_next_line(int fd)
// {
// 	int r;
// 	int rd;
// 	char *ret;

// 	rd = 0;
// 	ret = malloc(99999);
// 	if (!ret)
// 		return (NULL);
// 	if(fd < 0)
// 		return (NULL);
// 	r = read(fd, ret + rd, 1);
// 	rd += r;
// 	while (r != 0 && ret[rd -1] != '\n')
// 	{
// 		r = read(fd, ret + rd, 1);
// 		rd += r;
// 		if (r == -1)
// 		{
// 			free(ret);
// 			return (NULL);
// 		}
// 	}
// 	ret[rd] = '\0';
// 	if (!ret || !*ret)
// 	{
// 		free(ret);
// 		return (NULL);
// 	}
// 	return (ret);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	len;
	int	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	len = -1;
	while (s1[++len])
		str[len] = s1[len];
	j = 0;
	while (s2[j])
	{
		str[len++] = s2[j++];
	}
	str[len] = '\0';
	free(s1);
	return (str);
}

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
