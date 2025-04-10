
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBS = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re