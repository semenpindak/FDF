# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem <oem@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 15:56:07 by calpha            #+#    #+#              #
#    Updated: 2020/09/23 22:23:09 by oem              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
LIBFT		= Libft/libft.a
# MINILIBX	= minilibx_macos/libmlx.a
SRC			= fdf.c validation_file.c read_file.c line.c draw_map.c zoom.c move.c color.c\
			  rotate_left.c rotate_right.c
OBJ			= $(SRC:c=o)
CFLAGS		= -Wall -Wextra -Werror
LDLIBS 		= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	${CC} $(CFLAGS) ${OBJ} -L Libft/ -l ft -o ${NAME}

# $(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
# 	${CC} $(CFLAGS) ${OBJ} -L libft/ -l ft -L minilibx_macos/ $(LDLIBS) -o ${NAME}

$(LIBFT):
	make -C Libft/

# $(MINILIBX):
# 	make -C minilibx_macos/

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<

clean:
	rm -f $(OBJ) *.d && make clean -C Libft/

fclean: clean
	rm -f $(NAME) && make fclean -C Libft/

re: fclean all
