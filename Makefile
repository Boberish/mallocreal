ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif



NAME		= libft_malloc_$(HOSTTYPE).so
# NAME		= malloc

CC 			= gcc

SRC			= 	malloc.c \
				show_alloc_mem.c \
				free.c \
				realloc.c \

OBJ_PATH 	= ./obj/
OBJ_NAME 	= $(SRC:.c=.o)
OBJ 		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

FLAGS		= -Wall -Wextra -Werror 

# To make .o files (-c) in another folder
# -O0: Optimized for compilation time
# -g:  generate debugger info
$(OBJ_PATH)%.o: srcs/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c -o $@ $(FLAGS) $^

# Make shared library from object files
# symlink to simplified library name

# $(CC) -o $(NAME) $(OBJ) -L libft -lft

$(NAME): $(OBJ) makefile libft
	@rm -f libft_malloc.so
	@ $(CC) -shared -fPIC -o $(NAME) $(OBJ) -L libft -lft
	@ln -s $(NAME) libft_malloc.so
	@echo "\033[33;32m [✓] $(NAME) is ready" "\x1b[31m <3"

.PHONY:clean re all fclean

all: $(NAME)

libft:
	@make -C libft/ all

clean:
	@rm -rf $(OBJ_PATH)
	@rm -f libft_malloc.so
	@echo "\x1b[36m [✓] clean ok"

fclean: clean
	@rm -rf $(NAME)
	@echo "\x1b[36m [✓] fclean ok"

re: fclean $(NAME)
