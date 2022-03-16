STACK = init.c push.c rotate.c swap.c

STACK_DIR = src/stack/

CHECKER = checker.c

CHECKER_DIR = src/checker/

ALL_OBJ = $(STACK:.c=.o) $(CHECKER:.c=.o)

OBJ_DIR = obj/

LIBFT = libft/libft.a

INCLUDES = -I $(STACK_DIR) -I includes/ -I libft/
LINK = -L libft/ -lft


FLAGS = -Wall -Wextra -Werror
all: $(LIBFT)
	@gcc -c $(FLAGS) $(addprefix $(STACK_DIR), $(STACK)) $(INCLUDES)
	@gcc -c $(FLAGs) $(addprefix $(CHECKER_DIR), $(CHECKER)) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv $(ALL_OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(ALL_OBJ)) $(LINK)
	@echo "Compilation done"
$(LIBFT):
	@make -s -C libft/
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft/ clean
fclean: clean
	@rm -rf a.out
	@make -s -C libft/ fclean
re: fclean all