
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Iminilibx-linux -Ilibft -Ift_print


SRC_DIR = src
GNL_DIR = gnl
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
FTPRINT_DIR = ft_print


SRC = $(addprefix $(SRC_DIR)/, \
	check_file.c \
	main.c \
	read_file.c \
	img.c \
	player.c \
)

GNL = $(addprefix $(GNL_DIR)/, \
	get_next_line.c \
	get_next_line_utils.c \
)

SRCS = $(SRC) $(GNL)
OBJS = $(SRCS:.c=.o)


NAME = so_long


LIBS = \
	-L$(MLX_DIR) -lmlx \
	-L$(LIBFT_DIR) -lft \
	-L$(FTPRINT_DIR) -lftprintf \
	-lX11 -lXext -lm


all: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(FTPRINT_DIR)/libftprintf.a $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(FTPRINT_DIR)/libftprintf.a:
	$(MAKE) -C $(FTPRINT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(FTPRINT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(FTPRINT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
