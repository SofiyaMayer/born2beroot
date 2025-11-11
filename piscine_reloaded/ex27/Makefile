CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file

SRCS = 	ft_display_file.c

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