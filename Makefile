STACK = init.c push.c rotate.c swap.c

STACK_OBJ = $(STACK:.c=.o)
STACK_DIR = src/stack/
STACK_OBJ_NAME = $(addprefix $(STACK_DIR), $(STACK))

CHECKER = checker

CHECKER_SRC = checker.c read_line.c free_checker.c
CHECKER_DIR = src/checker/
CHECKER_OBJ = $(STACK:.c=.o) $(CHECKER_SRC:.c=.o)
CHECKER_OBJ_NAME = $(addprefix $(CHECKER_DIR), $(CHECKER_SRC)) $(STACK_OBJ_NAME)

PUSH_SWAP = push_swap

PUSH_SWAP_SRC = push_swap.c additional.c run.c groups.c
PUSH_SWAP_SRC += sort_large.c moves.c sort_small.c
PUSH_SWAP_SRC += check.c debug.c
PUSH_SWAP_DIR = src/push_swap/
PUSH_SAWP_OBJ_NAME = $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC)) $(STACK_OBJ_NAME)

PUSH_SWAP_OBJ = $(STACK:.c=.o) $(PUSH_SWAP_SRC:.c=.o)

ALL_OBJ = $(STACK:.c=.o) $(CHECKER_SRC:.c=.o) $(PUSH_SWAP_SRC:.c=.o)

OBJ_DIR = obj/

LIBFT = libft/libft.a

INCLUDES = -I $(STACK_DIR) -I includes/ -I libft/

LINK = -L libft/ -lft

FLAGS = -Wall -Wextra -Werror

all:$(CHECKER) $(PUSH_SWAP)
$(CHECKER): $(CHECKER_OBJ_NAME)
	@make -s -C libft/
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(FLAGS) $(addprefix $(STACK_DIR), $(STACK)) $(INCLUDES)
	@gcc -c $(FLAGS) $(addprefix $(CHECKER_DIR), $(CHECKER_SRC)) $(INCLUDES)
	@mv $(CHECKER_OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) -o $(CHECKER) $(LINK)
	@echo "Done compiling CHECKER"
$(PUSH_SWAP): $(PUSH_SAWP_OBJ_NAME)
	@make -s -C libft/
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(FLAGS) $(addprefix $(STACK_DIR), $(STACK)) $(INCLUDES)
	@gcc -c $(FLAGS) $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC)) $(INCLUDES)
	@mv $(PUSH_SWAP_OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ)) -o $(PUSH_SWAP) $(LINK)
	@echo "Done compiling PUSH_SWAP"
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft/ clean
fclean: clean
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@make -s -C libft/ fclean
re: fclean all