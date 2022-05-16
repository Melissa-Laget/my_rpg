##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -L. -lmy -I.

SRC	=	my_compute_square_root.c\
		my_compute_power_rec.c	\
		my_str_isprintable.c	\
		my_sort_int_array.c	\
		str_to_array_func.c	\
		my_strcapitalize.c	\
		my_long_to_int.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isupper.c	\
		str_start_with.c	\
		char_arr_utils.c	\
		for_str_in_str.c	\
		my_strlowcase.c		\
		my_put_float.c		\
		my_str_isnum.c		\
		my_strupcase.c		\
		str_to_array.c		\
		my_is_prime.c		\
		my_put_nbr.c		\
		my_putbase.c		\
		my_putchar.c		\
		my_showstr.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		resize_str.c		\
		void_utils.c		\
		str_utils.c		\
		my_getnbr.c		\
		my_revstr.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_strstr.c		\
		my_strcat.c		\
		is_in_str.c		\
		my_putstr.c		\
		my_strdup.c		\
		my_isneg.c		\
		my_swap.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

LIBNAME = libmy.a

all: $(LIBNAME)

$(LIBNAME): $(OBJ)
				ar rc $(LIBNAME) $(OBJ)
				cp $(LIBNAME) ../
				cp $(HEADER) ../../include/

clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(LIBNAME)
				rm -f ../$(LIBNAME)

re: fclean all
