##
## EPITECH PROJECT, 2018
## libmy.a
## File description:
## Makefile
##

SRC_DIR	=	.

LIB_DIR	=	..

SRC	=	$(SRC_DIR)/my_strlen.c	\
		$(SRC_DIR)/my_revstr.c	\
		$(SRC_DIR)/my_printf.c	\
		$(SRC_DIR)/add_delete_element.c\
		$(SRC_DIR)/binary_to_array.c\
		$(SRC_DIR)/get_next_line.c\
		$(SRC_DIR)/is_num.c\
		$(SRC_DIR)/my_array_dup.c\
		$(SRC_DIR)/my_array_len.c\
		$(SRC_DIR)/my_getnbr.c\
		$(SRC_DIR)/my_intlen.c\
		$(SRC_DIR)/my_print_binary.c\
		$(SRC_DIR)/my_put_digits.c\
		$(SRC_DIR)/my_strcmp.c\
		$(SRC_DIR)/my_strncmp.c\
		$(SRC_DIR)/my_strdup.c\
		$(SRC_DIR)/my_strdupcat.c\
		$(SRC_DIR)/puts.c\
		$(SRC_DIR)/my_binary_to_int.c\
		$(SRC_DIR)/my_compute_power_rec.c\
		$(SRC_DIR)/my_str_reduce.c\
		$(SRC_DIR)/my_str_to_word_array.c\
		$(SRC_DIR)/my_char_isalpha_num.c\
		$(SRC_DIR)/strstr.c\
		$(SRC_DIR)/print_return_msg.c\
		$(SRC_DIR)/my_int_to_char.c\
		$(SRC_DIR)/rand.c\
		$(SRC_DIR)/free_getline.c\

AR	=	ar rc

CC	=	gcc

CFLAGS	=	#-Wall -Wextra

CPPFLAGS=	-I../../includes/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	cp $(NAME) $(LIB_DIR)
	$(RM) $(NAME)

debug:	CFLAGS	+= -g3
debug:	all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB_DIR)/$(NAME)

.PHONY: fclean all clean
