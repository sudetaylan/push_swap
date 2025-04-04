SRCS	=	push_swap.c \
			cheapest.c \
			checker.c \
			free_end.c \
			init_nodes.c \
			operations.c \
			operations2.c \
			rotate_push.c \
			sort_big.c \
			sort_small.c \
			stack_utils.c \
			target.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft/

clean:
	@echo "[DELETING...]"
	rm -rf $(OBJS)
	make clean -C libft
	@echo "[DELETED]"

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all fclean clean re
