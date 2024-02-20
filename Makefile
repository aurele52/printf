# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <audreyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 01:52:00 by audreyer          #+#    #+#              #
#    Updated: 2022/08/08 15:54:43 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#

NAME = libftprintf.a

CC = gcc

FLAG = -Wall -Werror -Wextra

RM = rm -rf

INC = ./include/ft_printf.h

AR = ar rcs

FILE = ft_printf.c \
	   ft_printf_utils1.c \
	   ft_printf_utils2.c \
	   ft_printf_utils3.c

SRC = $(addprefix $(SRC_DIR),$(FILE))

OBJ = $(SRC:.c=.o)

SRC_DIR = src/

OBJ_DIR = src/

OBJ = $(SRC:.c=.o)

OUTB = $(SRCB:.c=.o)

$(NAME):	$(OBJ) $(INC)
		$(AR) $(NAME) $(OBJ)


all: $(NAME)

clean:
		$(RM) $(OUT) $(OUTB)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re

