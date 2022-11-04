#include "../cub3d.h"

char	*get_next_line(int fd)
{
	int r;
	int rd;
	char *ret;

	rd = 0;
	ret = malloc(99999);
	if (!ret)
		return (NULL);
	if(fd < 0)
		return (NULL);
	r = read(fd, ret + rd, 1);
	rd += r;
	while (r != 0 && ret[rd -1] != '\n')
	{
		r = read(fd, ret + rd, 1);
		rd += r;
		if (r == -1)
		{
			free(ret);
			return (NULL);
		}
	}
	ret[rd] = '\0';
	if (!ret || !*ret)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

