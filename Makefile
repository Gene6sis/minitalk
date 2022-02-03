# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 03:08:08 by adben-mc          #+#    #+#              #
#    Updated: 2022/01/30 23:55:08 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER		=	srcs/server.c
SRCS_CLIENT		=	srcs/client.c

SRCS_SERVER_B	=	bonus/server_bonus.c
SRCS_CLIENT_B	=	bonus/client_bonus.c

OBJS_SERVER		= 	${SRCS_SERVER:.c=.o}
OBJS_CLIENT		= 	${SRCS_CLIENT:.c=.o}

OBJS_SERVER_B	= 	${SRCS_SERVER_B:.c=.o}
OBJS_CLIENT_B	= 	${SRCS_CLIENT_B:.c=.o}

SERVER			= 	server
CLIENT			=	client

SERVER_B		= 	server_bonus
CLIENT_B		=	client_bonus

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -g3

PRINTF_DIR		=	ft_printf
PRINTF_LIB 		=	$(PRINTF_DIR)/libftprintf.a
PRINTF_FLAG  	=   -L ft_printf -lftprintf

all:		$(PRINTF_LIB) $(CLIENT) $(SERVER)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(CLIENT):	${OBJS_CLIENT}
			$(CC)  $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_FLAG) -o $(CLIENT)
			
$(SERVER):	${OBJS_SERVER}
			$(CC)  $(CFLAGS) $(OBJS_SERVER) $(PRINTF_FLAG) -o $(SERVER)
			
$(CLIENT_B):	${OBJS_CLIENT_B}
			$(CC)  $(CFLAGS) $(OBJS_CLIENT_B) $(PRINTF_FLAG) -o $(CLIENT_B)
			
$(SERVER_B):	${OBJS_SERVER_B}
			$(CC)  $(CFLAGS) $(OBJS_SERVER_B) $(PRINTF_FLAG) -o $(SERVER_B)

$(PRINTF_LIB):
	@$(MAKE) -sC ft_printf all

clean:
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT_B} ${OBJS_SERVER_B}
			@$(MAKE) -sC ft_printf clean

fclean:		clean
			${RM} ${CLIENT} ${SERVER} ${CLIENT_B} ${SERVER_B}
			@$(MAKE) -sC ft_printf fclean

re:			fclean all

bonus:		$(PRINTF_LIB) $(CLIENT_B) $(SERVER_B)

.PHONY:		all clean fclean re $(PRINTF_LIB) bonus
