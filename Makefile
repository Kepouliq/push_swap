NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = push_swap.h
			

SRCS = main.c\
		checks_input.c\
		utils.c\
		split.c\
		node_utils.c\
		error_and_free.c\
		init_stack.c\
		stack_utils.c\
		swap.c\
		rotate.c\
		reverse_rotate.c\
		push.c\
		sort_three.c\
		algo.c\
		algorithme_initit.c\



OBJS = ${SRCS:.c=.o}


all: $(NAME)

${NAME}: ${OBJS}
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all 

.PHONY: all clean fclean re