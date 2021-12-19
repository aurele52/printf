NAME = libftprintf.a

CC = gcc

INCLUDES = ../include

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar rcs

SRCS = ft_printf.c \
	   ft_printf_utils1.c \
	   ft_printf_utils2.c \
	   ft_printf_utils3.c

OUT = $(SRCS:.c=.o)

OUTB = $(SRCSB:.c=.o)

$(NAME): $(OUT)
		$(CC) $(FLAGS) -c $(SRCS)
		$(AR) $(NAME) $(OUT)

bonus: $(OUT) $(OUTB)
		$(CC) $(FLAGS) -c $(SRCS) $(SRCSB)
		$(AR) $(NAME) $(OUT) $(OUTB)

all: $(NAME)

clean:
		$(RM) $(OUT) $(OUTB)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus

