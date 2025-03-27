NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = srcs/libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/error.c \
		srcs/push_swap/find_cheapest.c \
		srcs/push_swap/free.c \
		srcs/push_swap/nbr_utils.c \
		srcs/push_swap/new_stack.c \
		srcs/push_swap/op_utils.c \
		srcs/push_swap/rotate_push.c \
		srcs/push_swap/sort_list.c \
		srcs/push_swap/sort_utils.c \
		srcs/push_swap/stack_op.c \
		srcs/push_swap/stack_op2.c \
		srcs/push_swap/target_utils.c \
		srcs/push_swap/targets.c

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}


INCLUDE = -L ./srcs/libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}


all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus