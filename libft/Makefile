# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-maul <pde-maul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:35:25 by jaylor            #+#    #+#              #
#    Updated: 2018/10/19 13:09:28 by pde-maul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERS = includes
NAME = libft.a
CFLAGS += -Wall -Werror -Wextra
CFLAGS += -I$(HEADERS)

FILESO =	ft_putchar.o \
			ft_putstr.o \
			ft_atoi.o \
			ft_itoa.o \
			ft_putnbr.o \
			ft_strndup.o \
			get_next_line.o \
			ft_memalloc.o \
			ft_strnew.o \
			ft_intlen.o \
			ft_strchr.o \
			ft_strrchr.o \
			ft_strdup.o \
			ft_abs.o \
			ft_strjoin.o \
			ft_strrev.o \
			ft_strcpy.o \
			ft_strlen.o \
			ft_putchar_fd.o \
			ft_putstr_fd.o \
			ft_abs.o \
			ft_abvpn.o \
			ft_allup.o \
			ft_bzero.o \
			ft_count_words.o \
			ft_first.o \
			ft_isalnum.o \
			ft_isalpha.o \
			ft_isascii.o \
			ft_isdigit.o \
			ft_isprint.o \
			ft_lstadd.o \
			ft_lstdel.o \
			ft_lstdelone.o \
			ft_lstiter.o \
			ft_lstmap.o \
			ft_lstnew.o \
			ft_memccpy.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_memcpy.o \
			ft_memdel.o \
			ft_memmove.o \
			ft_memset.o \
			ft_pfpchar.o \
			ft_printf.o \
			ft_printf_2.o \
			ft_printf_3.o \
			ft_printf_4.o \
			ft_printf_5.o \
			ft_printf_6.o \
			ft_putendl.o \
			ft_putendl_fd.o \
			ft_putnbr.o \
			ft_putnbr_fd.o \
			ft_putxchar.o \
			ft_strcat.o \
			ft_strchrfull.o \
			ft_strclr.o \
			ft_strcmp.o \
			ft_strcpy.o \
			ft_strdel.o \
			ft_strequ.o \
			ft_striter.o \
			ft_striteri.o \
			ft_strjoin.o \
			ft_strlcat.o \
			ft_strlen.o \
			ft_strmap.o \
			ft_strmapi.o \
			ft_strncat.o \
			ft_strncmp.o \
			ft_strncpy.o \
			ft_strnequ.o \
			ft_strnew.o \
			ft_strnstr.o \
			ft_strsplit.o \
			ft_strstr.o \
			ft_strsub.o \
			ft_strtrim.o \
			ft_tolower.o \
			ft_toupper.o \
			ft_trim_end.o \
		   	ft_unintlen.o \
			get_next_line.o \
			ft_print2d.o \
			ft_list_len.o \
			ft_intchr.o \
			ft_int_array_len.o \
			ft_intdup.o \
			ft_put_int_array.o \
			ft_intset.o \
			ft_intrev.o \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FILESO) makefile
	ar rc $(NAME) $^ 

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(FILESO) 

fclean: clean
	rm -f $(NAME)

re: fclean all
