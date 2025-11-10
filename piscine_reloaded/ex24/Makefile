CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = libft.a

SRCS = 	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc $(CFLAGS) $^

$(OBJS): %.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re