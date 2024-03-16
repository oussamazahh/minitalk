# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 23:02:59 by ozahidi           #+#    #+#              #
#    Updated: 2024/03/16 23:50:52 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SERVERNAME = server

CLIENTNAME = client

CFLAGS = #-Wall -Wextra -Werror

SRCS_S = ft_server/ft_server.c

SRCS_C = ft_client/ft_client.c

OBJSS = ${SRCS_S:.c=.o}

OBJSC= ${SRCS_C:.c=.o}

#%.o: %.c
#	${CC} -o $@ -c $<

all : ${OBJSS} ${OBJSC}
	${CC} ${CFLAGS} -o ${SERVERNAME}  ${OBJSS}
	${CC} ${CFLAGS} -o ${CLIENTNAME} ${OBJSC}
	
clean :
	rm -rf ${OBJSS} ${OBJSC}

fclean : clean
	rm -rf ${SERVERNAME} ${CLIENTNAME}

re : fclean all

.PHONY : clean fclean re all