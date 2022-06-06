STACK = init.c push.c rotate.c swap.c

STACK_DIR = src/stack/

CHECKER = checker

CHECKER_SRC = checker.c read_line.c free_checker.c

CHECKER_DIR = src/checker/

CHECKER_OBJ = $(STACK:.c=.o) $(CHECKER_SRC:.c=.o)

PUSH_SWAP = push_swap

PUSH_SWAP_SRC = push_swap.c additional.c run.c groups.c
PUSH_SWAP_SRC += sort_large.c moves.c sort_small.c
PUSH_SWAP_SRC += check.c debug.c

PUSH_SWAP_DIR = src/push_swap/

PUSH_SWAP_OBJ = $(STACK:.c=.o) $(PUSH_SWAP_SRC:.c=.o)

ALL_OBJ = $(STACK:.c=.o) $(CHECKER_SRC:.c=.o) $(PUSH_SWAP_SRC:.c=.o)

OBJ_DIR = obj/

LIBFT = libft/libft.a

INCLUDES = -I $(STACK_DIR) -I includes/ -I libft/

LINK = -L libft/ -lft

FLAGS = -Wall -Wextra -Werror

all: $(LIBFT)
	@gcc -c $(FLAGS) $(addprefix $(STACK_DIR), $(STACK)) $(INCLUDES)
	@gcc -c $(FLAGS) $(addprefix $(CHECKER_DIR), $(CHECKER_SRC)) $(INCLUDES)
	@gcc -c $(FLAGS) $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC)) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv $(ALL_OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -o $(CHECKER) $(LINK)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ)) -o $(PUSH_SWAP) $(LINK)
	@echo "Compilation done"
$(LIBFT):
	@make -s -C libft/
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft/ clean
fclean: clean
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@make -s -C libft/ fclean
re: fclean all