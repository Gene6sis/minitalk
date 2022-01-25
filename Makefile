# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 03:08:08 by adben-mc          #+#    #+#              #
#    Updated: 2022/01/25 18:42:45 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER	=	srcs/server.c
SRCS_CLIENT	=	srcs/client.c

OBJS_SERVER	= 	${SRCS_SERVER:.c=.o}
OBJS_CLIENT	= 	${SRCS_CLIENT:.c=.o}

SERVER	= 	server
CLIENT	=	client

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

PRINTF_DIR	=	ft_printf
PRINTF_LIB 	=	$(PRINTF_DIR)/libftprintf.a
PRINTF_FLAG  =   -L ft_printf -lftprintf

all:		$(PRINTF_LIB) $(CLIENT) $(SERVER)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(CLIENT):	${OBJS_CLIENT}
			$(CC)  $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_FLAG) -o $(CLIENT)
#			@$(MAKE) -sC ft_printf all
#			ar -rcs $(CLIENT) $(OBJS_CLIENT) ft_printf/*.o
			
$(SERVER):	${OBJS_SERVER}
			$(CC)  $(CFLAGS) $(OBJS_SERVER) $(PRINTF_FLAG) -o $(SERVER)
#			ar -rcs $(SERVER) $(OBJS_SERVER) ft_printf/*.o

$(PRINTF_LIB):
	@$(MAKE) -sC ft_printf all

clean:
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
			@$(MAKE) -sC ft_printf clean

fclean:		clean
			${RM} ${CLIENT} ${SERVER}
			@$(MAKE) -sC ft_printf fclean

re:			fclean all

.PHONY:		all clean fclean re $(PRINTF_LIB)
