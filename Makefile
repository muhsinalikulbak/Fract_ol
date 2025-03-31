# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 00:38:33 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/31 02:58:15 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./

MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

# Mandatory sources - Zorunlu kısım için kaynak dosyaları
SRCS_DIR = mandatory
SRCS = $(addprefix $(SRCS_DIR)/, \
	fract_ol.c argv_checker.c calc_fractal.c mlx_utils.c initializer.c dimensions.c event.c)

# Bonus sources - Bonus kısım için kaynak dosyaları
BONUS_DIR = bonus
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, \
	fract_ol.c argv_checker.c calc_fractal.c mlx_utils.c initializer.c \
	dimensions.c event.c hook.c julia.c mandelbrot.c burning_ship.c tricorn.c color.c \
	change_iter.c)

MAKEFLAGS += --silent

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(MLX) $(LIBFT) 
	echo "✅ Creating $(NAME).."
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	echo "✅ $(NAME) Ready!"

$(BONUS): $(MLX) $(LIBFT) 
	echo "✅ Creating $(BONUS).."
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_SRCS) $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	echo "✅ $(BONUS) Ready!"

$(MLX):
	echo "🔷 Compiling MLX..."
	make -C $(MLX_PATH) --no-print-directory
	echo "✅ MLX Ready!"

$(LIBFT):
	echo "🔷 Compiling LIBFT..."
	make -C $(LIBFT_PATH) --no-print-directory
	echo "✅ LIBFT Ready!"

clean:
	echo "🧹 Being Cleaned..."
	make -C $(MLX_PATH) clean --no-print-directory
	make -C $(LIBFT_PATH) clean --no-print-directory
	echo "✅ Cleaning completed!"

fclean: clean
	echo "🧹 Full cleaning is in progress..."
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_PATH) fclean --no-print-directory
	echo "✅ Full cleaning completed!"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus