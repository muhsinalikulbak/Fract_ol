# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:20:26 by mkulbak           #+#    #+#              #
#    Updated: 2025/03/13 19:20:27 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Imlx

MLX_PATH	= minilibx-linux
MLX			= $(MLX_PATH)/libmlx.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS	= fract_ol.c

OBJS	= $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

all: $(NAME)

makemlx:
	@make -C $(MLX_PATH)

makelibft:
	@make -C $(LIBFT_PATH)

$(NAME): makemlx makelibft $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX) $(LIBFT) $(MLX_FLAGS)

clean:
	@rm -f $(OBJS)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean

re: fclean all