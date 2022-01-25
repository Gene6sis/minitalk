SRCS	=	ft_atoi.c				\
			ft_isascii.c 			\
			ft_memcpy.c  			\
			ft_strlcpy.c 			\
			ft_strtrim.c			\
			ft_bzero.c  			\
			ft_isdigit.c			\
			ft_memmove.c			\
			ft_strdup.c 			\
			ft_strlen.c 			\
			ft_substr.c				\
			ft_calloc.c				\
			ft_isprint.c 			\
			ft_memset.c  			\
			ft_strncmp.c 			\
			ft_tolower.c			\
			ft_isalnum.c 			\
			ft_memchr.c  			\
			ft_strchr.c  			\
			ft_strjoin.c 			\
			ft_strnstr.c 			\
			ft_toupper.c 			\
			ft_isalpha.c 			\
			ft_memcmp.c  			\
			ft_strlcat.c 			\
			ft_split.c	 			\
			ft_putchar_fd.c 		\
			ft_strrchr.c			\
			ft_itoa.c				\
			ft_putstr_fd.c			\
			ft_putnbr_fd.c			\
			ft_putendl_fd.c			\
			ft_strmapi.c			\
			ft_striteri.c

SRCSBONUS =	ft_lstnew.c				\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstdelone.c			\
			ft_lstiter.c			\
			ft_lstclear.c			\
			ft_lstadd_front.c		\
			ft_lstadd_back.c		\
			ft_lstmap.c	

OBJS	= 	${SRCS:.c=.o}

OBJSBON	= 	${SRCSBONUS:.c=.o}

NAME	= 	libft.a

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			${RM} ${OBJSBON} ${OBJS}

fclean:		clean
			${RM} ${NAME} 

bonus:		${OBJSBON} ${OBJS}
			ar -rcs $(NAME) ${OBJSBON} ${OBJS}

re:			fclean all

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCSBONUS) $(SRCS) 
#	gcc -nostartfiles -shared -o libft.so $(OBJSBON) $(OBJS) 

.PHONY:		bonus all clean fclean re