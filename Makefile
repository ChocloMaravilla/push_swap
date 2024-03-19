HEADER	=	push_swap.h

NAME	=	push_swap

SRCS	=	push_swap.c \
push_swap_utils.c \
push_swap_functions_1.c \
push_swap_functions_2.c \
push_swap_functions_3.c \
push_swap_instructions_1.c \
push_swap_instructions_2.c \
push_swap_instructions_3.c

OBJS	=	$(SRCS:.c=.o)
CC	= 	gcc
RM	= 	rm -f
LIBC	= 	ar rcs
FLAGS	= 	-Wall -Wextra -Werror

%.o : %.c Makefile ${HEADER} 
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS} 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
