NAME	= libmlx.a
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c font.c
OBJ1	= $(SRC:c=o)
OBJ		= $(OBJ1:m=o)
CFLAGS	= -O2

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
	rm -f mlx_app

fclean: clean
	rm -f $(NAME)

re: clean all
