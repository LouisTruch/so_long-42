# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:41:42 by ltruchel          #+#    #+#              #
#    Updated: 2022/12/01 18:35:35 by ltruchel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c \
			parsing/main_parsing.c \
			parsing/map_copy.c \
			parsing/map_test_file.c \
			parsing/map_test_path_collectible.c \
			parsing/map_test_path_exit.c \
			parsing/map_test_paths.c \
			parsing/map_test_rectangular.c \
			parsing/map_test_requirements.c \
			parsing/map_test_wall.c \
			parsing/parsing_free_functions.c \
			game/initiate/initialise.c \
			game/initiate/initialise_map.c \
			game/load/loading.c \
			game/load/loading_enemy.c \
			game/loop/animate_collectible.c \
			game/loop/animation.c \
			game/loop/background_replacement.c \
			game/loop/check_functions.c \
			game/loop/enemy_check_move_functions.c \
			game/loop/enemy_move_functions.c \
			game/loop/input.c \
			game/loop/swap_sprites.c \
			game/free_functions.c \

OBJS	=	${SRCS:.c=.o}

LIB		=	libft/libft.a \
			minilibx-linux/libmlx.a

CC	= 	clang

CFLAGS	=	-g

RM		=	rm -f

all		:	${NAME}

.c.o	:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	: ${OBJS}
		make -C libft
		make -C minilibx-linux
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB} -lXext -lX11 
	
clean	:
		make -C libft clean
		${RM} ${OBJS}

fclean	:	clean
		make -C libft fclean
		${RM} ${NAME}

re		:	fclean all

.PHONY: all clean fclean re
