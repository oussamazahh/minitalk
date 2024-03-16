# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 12:44:10 by ozahidi           #+#    #+#              #
#    Updated: 2024/03/16 12:48:26 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

AR = ar

SRCS = ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memmove.c ft_strchr.c ft_strlen.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c ft_atoi.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_memmove.c \
	ft_strnstr.c ft_strlcpy.c ft_isalpha.c ft_calloc.c ft_strdup.c \
	ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}

BOBJS= ${BSRCS:.c=.o}

%o : %c libft.h
	${CC} -o $@ ${CFLAGS} -c $<

all : ${NAME}

${NAME} : ${OBJS}
	${AR} rcs ${NAME} ${OBJS}

bonus : ${BOBJS}
	${AR} rcs ${NAME} ${BOBJS}

clean :
	rm -rf ${OBJS} ${BOBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean re all bonus