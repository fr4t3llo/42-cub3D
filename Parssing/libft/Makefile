# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 02:56:18 by skasmi            #+#    #+#              #
#    Updated: 2021/11/24 07:03:15 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc 
FLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c	ft_memchr.c	ft_strncmp.c ft_toupper.c\
	  ft_isascii.c ft_memcmp.c	ft_strchr.c	ft_strnstr.c\
	  ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcpy.c ft_strrchr.c\
	  ft_isalnum.c	ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c\
	  ft_memmove.c ft_strdup.c ft_substr.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_atoi.c ft_strlcat.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_strmapi.c ft_striteri.c ft_split.c ft_itoa.c ft_strjoin.c ft_strtrim.c\

OBJET = $(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJET)
		ar rcs $(NAME) $(OBJET)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $< 
clean : 
	rm -f $(OBJET)
fclean : 
	rm -f $(NAME)
re : clean fclean all
