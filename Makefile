# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 23:02:59 by ozahidi           #+#    #+#              #
#    Updated: 2024/03/18 14:37:07 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SERVERNAME = server

CLIENTNAME = client

CFLAGS = #-Wall -Wextra -Werror

# libft = make -c libft/

# ft_printf = make -c ft_printf/

SRCS_S = ft_server/ft_server.c

SRCS_C = ft_client/ft_client.c

OBJSS = ${SRCS_S:.c=.o}

OBJSC= ${SRCS_C:.c=.o}

%.o: %.c
	${CC} -o $@ -c $<

all : ${SERVERNAME} ${CLIENTNAME}

${SERVERNAME}: ${OBJSS}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} -o ${SERVERNAME}  ${OBJSS}  libft/libft.a ft_printf/libftprintf.a

${CLIENTNAME}: ${OBJSC}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} -o ${CLIENTNAME}  ${OBJSC}  libft/libft.a ft_printf/libftprintf.a
 	
clean :
	make clean -C libft/
	make clean -C ft_printf/
	rm -rf ${OBJSS} ${OBJSC}

fclean : clean
	make fclean -C libft/
	make fclean -C ft_printf/
	rm -rf ${SERVERNAME} ${CLIENTNAME}
	

re : fclean all

.PHONY : clean fclean re all