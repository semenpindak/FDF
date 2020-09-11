LIBFT	= libft/libft.a

NAME	= fdf

SRC		= fdf.c create_map.c

OBJ		= $(SRC:c=o)

CFLAGS	= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	${CC} $(CFLAGS) ${OBJ} -L libft/ -l ft -o ${NAME}

$(LIBFT):
	make -C libft/

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -f $(OBJ) *.d .DS_Store && make clean -C libft/

fclean: clean
	rm -f $(NAME) && make fclean -C libft/

re: fclean all
