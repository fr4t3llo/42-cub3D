/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:38 by skasmi            #+#    #+#             */
/*   Updated: 2022/12/22 00:56:41 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
//# include <mlx.h>
# include <math.h>
# include <time.h>
# define BUFFER_SIZE 1

typedef struct s_map
{
    char    *tab;
    char    **map2d;
    int     fd;
	int		map_width;
	int		map_height;
}           t_map;

typedef struct s_texture
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
}			t_texture;

// parssing functions
int		ft_check_map_one(char **tab);
int		ft_check_all_map(char **map);
int		ft_check_all_map2(t_map *map);
int		error(t_map *map);
int 	get_len(char **str);
void	retrun_map_2d(t_map *map);
int 	ft_get_len_ofmap(char **str);

// libft functions
int     ft_strlen(const char *str);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(char *s1);

// get next line functions 
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_line(char *str);
char	*ft_read(char *str, int fd);
char	*ft_rest(char *st);
char	*ft_strjoin(char *s1, char *s2);

#endif
