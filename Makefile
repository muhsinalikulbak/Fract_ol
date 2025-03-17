# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:20:26 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/17 14:59:48 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_PATH = minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = fract_ol.c  checker_utils.c fractals.c mlx_utils.c
OBJS = $(SRCS:.c=.o)

MAKEFLAGS += --silent

all: $(NAME) clean_obj

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	echo "✅ $(NAME) oluşturuluyor..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(MLX_FLAGS)
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
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean --no-print-directory
	make -C $(LIBFT_PATH) clean --no-print-directory
	echo "✅ Temizlik tamamlandı!"

clean_obj:
				$(RM) $(OBJS)
fclean: clean
	echo "🧹 Tam temizlik yapılıyor..."
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory
	echo "✅ Tam temizlik tamamlandı!"

re: fclean all

.PHONY: all clean fclean re