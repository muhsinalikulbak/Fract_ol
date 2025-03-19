# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:20:26 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/20 00:35:53 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS =   -Imlx

MLX_PATH = minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = fract_ol.c  argv_checker.c fractals.c mlx_utils.c initializer.c dimensions.c

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) 
	echo "✅ $(NAME) oluşturuluyor..."
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX) $(LIBFT) $(MLX_FLAGS)
	echo "✅ $(NAME) hazır!"

$(MLX):
	echo "🔷 MLX derleniyor..."
	make -C $(MLX_PATH) --no-print-directory
	echo "✅ MLX hazır!"

$(LIBFT):
	echo "🔷 LIBFT derleniyor..."
	make -C $(LIBFT_PATH) --no-print-directory
	echo "✅ LIBFT hazır!"

clean:
	echo "🧹 Temizleniyor..."
	make -C $(MLX_PATH) clean --no-print-directory
	make -C $(LIBFT_PATH) clean --no-print-directory
	echo "✅ Temizlik tamamlandı!"

fclean: clean
	echo "🧹 Tam temizlik yapılıyor..."
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory
	echo "✅ Tam temizlik tamamlandı!"

re: fclean all

.PHONY: all clean fclean re