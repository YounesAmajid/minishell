# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:09:42 by asabri            #+#    #+#              #
#    Updated: 2023/07/06 02:30:01 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC	= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr \
	ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
	ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_putchar_fd \
	ft_putstr_fd ft_putendl_fd ft_strtrim ft_strjoin ft_itoa ft_putnbr_fd ft_strmapi ft_split ft_striteri fd_printf

OBJS = ${SRC:=.o}

all : $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o : %.c libft.h
	${CC} ${CFLAGS} -c $<
clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f $(NAME)

re: fclean all
