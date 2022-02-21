
NAME = push_swap.a

CC = gcc

INCLUDES = ../include

FLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

AR = ar rcs

SRCS = aurele_sort_utils_2.c	\
       aurele_sort_utils.c	\
       ft_list.c	\
       ft_lstinfo.c	\
       push.c	\
       push_swap.c	\
       push_swap_utils.c	\
       rotate2.c	\
       rotate.c	\
       swap.c


OUT = $(SRCS:.c=.o)

OUTB = $(SRCSB:.c=.o)

$(NAME): $(OUT)
		$(CC) $(FLAGS) -c $(SRCS) 
		$(AR) $(NAME) $(OUT)
		gcc -o push_swap push_swap.a

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
