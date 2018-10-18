ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif



NAME		= libft_malloc_$(HOSTTYPE).so
# NAME		= malloc

CC 			:= gcc



SRC			+= malloc.c
SRC			+= show_alloc_mem.c
SRC			+= free.c
SRC			+= realloc.c
# SRC			+= show_alloc_mem.c


OBJ_PATH 	= ./obj/
OBJ_NAME 	= $(SRC:.c=.o)
OBJ 		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# CFLAGS		:= -Wall -Wextra -Werror -fsanitize=address
CFLAGS		:= -Wall -Wextra -Werror 

# To make .o files (-c) in another folder
# -O0: Optimized for compilation time
# -g:  generate debugger info
$(OBJ_PATH)%.o: srcs/%.c
	mkdir -p $(OBJ_PATH)
	$(CC) -c -o $@ $(CFLAGS) $^  -g 
	echo -n .

# Make shared library from object files
# symlink to simplified library name
$(NAME): $(OBJ) makefile
	# $(CC) -o $(NAME) $(OBJ) -L libft -lft
	$(CC) -shared -fPIC -o $(NAME) $(OBJ) -L libft -lft
	ln -s $(NAME) libft_malloc.so
	# @echo "[MALLOC compiled.]\n"

all: $(NAME)

libft:
	make -C libft/ all

clean:
	rm -rf $(OBJ_PATH)
	rm -f libft_malloc.so

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
