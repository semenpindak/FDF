# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calpha <calpha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 15:56:07 by calpha            #+#    #+#              #
#    Updated: 2020/09/26 22:47:09 by calpha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
LIBFT		= libft/libft.a
MINILIBX	= minilibx_macos/libmlx.a
SRC			= fdf.c validation_file.c check_min_max_number.c read_file.c line.c draw_map.c zoom.c move.c\
			  color.c free_array.c rotate_x.c rotate_y.c rotate_z.c
OBJ			= $(SRC:c=o)
CFLAGS		= -Wall -Wextra -Werror
LDLIBS 		= -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	${CC} $(CFLAGS) ${OBJ} -L libft/ -l ft -L minilibx_macos/ $(LDLIBS) -o ${NAME}

$(LIBFT):
	make -C libft/

$(MINILIBX):
	make -C minilibx_macos/

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -f $(OBJ) *.d && make clean -C libft/ && make clean -C minilibx_macos/

fclean: clean
	rm -f $(NAME) && make fclean -C libft/ && make fclean -C minilibx_macos/

re: fclean all
