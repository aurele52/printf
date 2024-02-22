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

NAME = printf.a

CC = gcc

FLAGS = -g -Wall -Werror -Wextra -MMD

RM = rm -rf

INC = include/ft_printf.h

-include ${DOBJ}

.c.o:
			$(CC) $(FLAGS) -I include -c $< -o $(<:.c=.o)

AR = ar -crs

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR),$(FILE))

FILE = ft_printf.c \
	   ft_printf_utils1.c \
	   ft_printf_utils2.c \
	   ft_printf_utils3.c

OBJ = $(SRC:.c=.o)

DOBJ		=	${SRC:.c=.d}

$(NAME):	$(OBJ) $(INC)
		$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
		${RM} $(OBJ) ${DOBJ} ${OBJB} ${DOBJB}

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re .c.o
