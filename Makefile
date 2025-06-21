# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 00:38:33 by mkulbak           #+#    #+#              #
#    Updated: 2025/06/22 01:11:58 by muhsin           ###   ########.fr        #
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

# Mandatory sources
SRCS_DIR = mandatory
SRCS = $(addprefix $(SRCS_DIR)/, \
	fract_ol.c argv_checker.c calc_fractal.c mlx_utils.c initializer.c dimensions.c event.c)
OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

# Bonus sources
BONUS_DIR = bonus
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, \
	fract_ol.c argv_checker.c calc_fractal.c mlx_utils.c initializer.c \
	dimensions.c event.c hook.c julia.c mandelbrot.c burning_ship.c tricorn.c \
	change.c dynamic_julia.c)
BONUS_OBJS_DIR = obj_bonus
BONUS_OBJS = $(patsubst $(BONUS_DIR)/%.c,$(BONUS_OBJS_DIR)/%.o,$(BONUS_SRCS))

MAKEFLAGS += --silent

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(MLX) $(LIBFT) $(OBJS_DIR) $(OBJS)
	echo "✅ Creating $(NAME).."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	echo "✅ $(NAME) Ready!"

$(BONUS): $(MLX) $(LIBFT) $(BONUS_OBJS_DIR) $(BONUS_OBJS)
	echo "✅ Creating $(BONUS).."
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	echo "✅ $(BONUS) Ready!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)

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
	rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
	echo "✅ Cleaning completed!"

fclean: clean
	echo "🧹 Full cleaning is in progress..."
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_PATH) fclean --no-print-directory
	echo "✅ Full cleaning completed!"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus