/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:24:54 by skasmi            #+#    #+#             */
/*   Updated: 2023/01/17 23:41:36 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../cub3d.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>


int		ft_isalpha(int nb);
void	ft_bzero(void *str, size_t n);
int		ft_isalnum(int n);
int		ft_isascii(int str);
int		ft_isdigit(int nb);
int		ft_isprint(int s);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memmove(void *str1, const void *str2, size_t n);
char	*ft_strchr(char *str, int c);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int nb);
int		ft_toupper(int nb);
void	*ft_calloc(size_t count, size_t size);
long long		ft_atoi(const char *str);
char	*ft_substr(char *s, int start, int len);
// char	*ft_strdup(const char *s1);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char *set);


//list
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_back(t_list **lst,	t_list *new);
// t_list	*ft_lstlast(t_list *lst);

#endif
