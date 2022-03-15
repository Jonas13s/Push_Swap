STACK = init.c push.c rotate.c swap.c

STACK_DIR = src/stack/

OBJ_DIR = obj/
FLAGS = -Wall -Wextra -Werror
all:
	@gcc -c $(FLAGS) $(addprefix $(STACK_DIR), $(STACK))
	@mkdir -p $(OBJ_DIR)
	@mv $(STACK:.c=.o) $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)