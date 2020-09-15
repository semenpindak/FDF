LIBFT		= libft/libft.a
MINILIBX	= minilibx_macos/libmlx.a
NAME		= fdf
SRC			= fdf.c read_file.c line.c draw_map.c
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
	rm -f $(OBJ) *.d .DS_Store && make clean -C libft/ && make clean -C minilibx_macos/

fclean: clean
	rm -f $(NAME) && make fclean -C libft/ && make fclean -C minilibx_macos/

re: fclean all
