/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:38 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/18 01:13:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <time.h>
# define BUFFER_SIZE 1
# define INC 60

typedef struct s_list
{	
	char			*var;
	char			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_map
{
    char    *tab;
    char    **all_map2d;
	char	**only_map;
    char    *export_only_map;
	char	**txt_rgb;
    int     fd;
	int		map_width;
	int		map_height;
	void	*mlx_ptr;	
	void	*mlx_win;
	void	*mlx_red;
	void	*mlx_chibi;
	void	*mlx_rose;
	void	*mlx_jnbfo9;
	void	*mlx_jnbte7t;
	void	*mlx_rightte7t;
	void	*mlx_rightfo9;
	int		width;
	int		height;
	int		line_empty;
}           t_map;

typedef struct s_texture
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
}			t_texture;

typedef struct s_rgb
{
	long long r_F;
	long long g_F;
	long long b_F;
	long long r_C;
	long long g_C;
	long long b_C;
}		t_rgb;	

// parssing functions
int		ft_check_map_one(char **tab);
int		ft_check_all_map(char **map);
int		ft_check_all_map2(t_map *map);
int 	ft_check_horizontal(t_map *map);
int 	ft_check_vertical(t_map *map);
int		error(t_map *map);
int 	get_len(char **str);
void	retrun_map_2d(t_map *map);
int 	ft_get_len_ofmap(char **str);
void	check_line_txt_rgb(char *str, t_map *map);
int 	ft_check_line_ifnotinmap(char *line);
void 	ft_check_line_before_map(char **str, t_map *map);
int		ft_check_number_of_comma(char *str);
void 	ft_check_map_len(t_map *t);

                //RGB FUNCTIONS
void	ft_check_txt(char *line, char *test, t_map *map);
int 	ft_check_rgb_error_f(char *line, t_rgb t);
int 	ft_check_rgb_error_c(char *line, t_rgb t);
void	ft_check_color2(char *line, t_map *map);
void	ft_check_color(char *line, t_map *map);


// libft functions
int     ft_strlen(char *str);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
long long	ft_atoi(const char *str);

// list libft
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst,	t_list *new);
t_list	*ft_lstlast(t_list *lst);

// get next line functions 
char	*get_next_line(int fd);
// char	*ft_strchr(char *s, int c);
char	*ft_line(char *str);
char	*ft_read(char *str, int fd);
char	*ft_rest(char *st);
char	*ft_strjoin(char *s1, char *s2);

#endif
