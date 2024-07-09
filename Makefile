# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 23:02:59 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/02 15:36:47 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = server

CLIENTNAME = client

BSERVERNAME = server_bonus

BCLIENTNAME = client_bonus

CFLAGS = -Wall -Wextra -Werror


SRC_S = $(SRCS_S) $(SRCS_U)
SRC_C = $(SRCS_C)


OBJ_S = ${SRC_S:.c=.o}
OBJ_C = ${SRC_C:.c=.o}


BSRC_S = $(BSRCS_S)
BSRC_C = $(BSRCS_C)

BOBJ_S = ${BSRC_S:.c=.o}
BOBJ_C = ${BSRC_C:.c=.o}

SRCS_S = Mandatory/ft_server.c
SRCS_U = Mandatory/utils.c
SRCS_C = Mandatory/ft_client.c

BSRCS_S = bonus/ft_server_bonus.c bonus/utils_bonus_server.c
BSRCS_C = bonus/ft_client_bonus.c bonus/utils_bonus_client.c


all : ${NAME} ${CLIENTNAME}

${NAME}:  $(OBJ_S)
	@make -C libft/
	@make -C ft_printf/
	${CC} ${CFLAGS} -o ${NAME} ${OBJ_S} libft/libft.a ft_printf/libftprintf.a

${CLIENTNAME}: $(OBJ_C)
	${CC} ${CFLAGS} -o ${CLIENTNAME}  ${OBJ_C}  libft/libft.a ft_printf/libftprintf.a

bonus: ${BSERVERNAME} ${BCLIENTNAME}

${BSERVERNAME}:  $(BOBJ_S)
	@make -C libft/
	@make -C ft_printf/
	@${CC} ${CFLAGS} -o ${BSERVERNAME} ${BOBJ_S} libft/libft.a ft_printf/libftprintf.a

${BCLIENTNAME}: $(BOBJ_C)
	@${CC} ${CFLAGS} -o ${BCLIENTNAME}  ${BOBJ_C}  libft/libft.a ft_printf/libftprintf.a

clean :
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -rf ${OBJ_S} ${OBJ_C}
	@rm -rf ${BOBJ_C} ${BOBJ_S}

fclean : clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf ${CLIENTNAME} ${NAME}
	@rm -rf ${BSERVERNAME} ${BCLIENTNAME}

re : fclean all

.PHONY : clean fclean re all bonus