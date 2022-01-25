# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 16:44:53 by adben-mc          #+#    #+#              #
#    Updated: 2022/01/25 04:33:10 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c		\
			ft_putstr.c		\
			ft_convert.c	\
			ft_putnbr.c		\
			ft_putunbr.c	\
			ft_putchar.c	\
			ft_pointer.c

OBJS	= 	${SRCS:.c=.o}

NAME	= 	libftprintf.a

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@$(MAKE) -sC libft all
			ar -rcs $(NAME) $(OBJS) libft/*.o

all:		${NAME}

clean:
			${RM} ${OBJSBON} ${OBJS}
			@$(MAKE) -sC libft clean

fclean:		clean
			${RM} ${NAME}
			@$(MAKE) -sC libft fclean

re:			fclean all

.PHONY:		all clean fclean re
