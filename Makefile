# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 23:02:59 by ozahidi           #+#    #+#              #
#    Updated: 2024/03/24 00:40:26 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SERVERNAME = server

CLIENTNAME = client

CFLAGS = -Wall -Wextra -Werror

# libft = make -c libft/
# ft_printf = make -c ft_printf/

SRCS_S = Mandatory/ft_server.c
SRCS_U = Mandatory/utils.c
SRCS_C = Mandatory/ft_client.c

BSRCS_S = bonus/ft_server_bonus.c
BSRCS_U = bonus/utils_bonus.c
BSRCS_C = bonus/ft_client_bonus.c
# BSRCS_S = ft_server/ft_server_bonus.c


# BSRCS_C = ft_client/ft_client_bonus.c

OBJSS = ${SRCS_S:.c=.o}
OBJSU = ${SRCS_U:.c=.o}
OBJSC= ${SRCS_C:.c=.o}

BOBJSS = ${BSRCS_S:.c=.o}
BOBJSU = ${BSRCS_U:.c=.o}
BOBJSC = ${BSRCS_C:.c=.o}

%.o: %.c 
	${CC} -o $@ ${CFLAGS} -c $<

all : ${SERVERNAME} ${CLIENTNAME}

# bonus : ${BSERVERNAME} ${BCLIENTNAME}

${SERVERNAME}: ${OBJSS} ${OBJSU}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} -o ${SERVERNAME}  ${OBJSS} ${OBJSU} libft/libft.a ft_printf/libftprintf.a

${CLIENTNAME}: ${OBJSC}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} -o ${CLIENTNAME}  ${OBJSC}  libft/libft.a ft_printf/libftprintf.a

bonus: ${BOBJSS} ${BOBJSU} ${BOBJSC}
	make -C libft/
	make -C ft_printf/
	${CC} ${CFLAGS} -o ${SERVERNAME}  ${BOBJSS} ${BOBJSU}  libft/libft.a ft_printf/libftprintf.a
	${CC} ${CFLAGS} -o ${CLIENTNAME}  ${BOBJSC} ${BOBJSU}  libft/libft.a ft_printf/libftprintf.a
 	
clean :
	make clean -C libft/
	make clean -C ft_printf/
	rm -rf ${OBJSS} ${OBJSC} ${OBJSU}
	rm -rf ${BOBJSS} ${BOBJSC} ${BOBJSU}

fclean : clean
	make fclean -C libft/
	make fclean -C ft_printf/
	rm -rf ${SERVERNAME} ${CLIENTNAME}
	

re : fclean all

.PHONY : clean fclean re all