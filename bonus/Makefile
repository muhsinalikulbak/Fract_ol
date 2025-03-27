# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:20:26 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/28 01:20:16 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror  -I../

MLX_PATH = ../minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

SRCS = fract_ol.c argv_checker.c calc_fractal.c mlx_utils.c initializer.c \
 dimensions.c event.c julia.c mandelbrot.c burning_ship.c tricorn.c  color.c \
 change_iter.c

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) 
	echo "✅ creating $(NAME).."
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	echo "✅ $(NAME) ready!"

$(MLX):
	echo "🔷 Compiling MLX..."
	make -C $(MLX_PATH) --no-print-directory
	echo "✅ MLX ready!"

$(LIBFT):
	echo "🔷 Compiling LIBFT..."
	make -C $(LIBFT_PATH) --no-print-directory
	echo "✅ LIBFT ready!"

clean:
	echo "🧹 Temizleniyor..."
	make -C $(MLX_PATH) clean --no-print-directory
	make -C $(LIBFT_PATH) clean --no-print-directory
	echo "✅ Temizlik tamamlandı!"

fclean: clean
	echo "🧹 Full cleaning is in progress..."
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory
	echo "✅ Full cleaning completed!"

re: fclean all

.PHONY: all clean fclean re
