# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calpha <calpha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 13:33:10 by calpha            #+#    #+#              #
#    Updated: 2020/09/22 13:46:30 by calpha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
PROGRAM := fdf

# Name of the own library.
LIBFT	:= Libft/libft.a

# Name of the graphics library.
MINILIBX:= minilibx_macos/libmlx.a

# Name of the directories.
INC_DIR := FDF/includes
SRC_DIR := FDF/srcs
OBJ_DIR := FDF/objs

# Path of the directories.
INCLS	:= $(INC_DIR)
SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Define all the compiling flags.
CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra
LDLIBS 	:= -lmlx -framework OpenGL -framework AppKit

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean re

# Compile and create everything.
all:	obj
		$(MAKE) $(PROGRAM)

# Creates the object files' directory.
obj:
		mkdir $(OBJ_DIR)

# This won't run if the object files don't exist or are not modified.
$(PROGRAM): $(LIBFT) $(MINILIBX) ${OBJS}
		${CC} $(CFLAGS) ${OBJS} -o $@ -L Libft/ -lft -L minilibx_macos/ $(LDLIBS) -o ${NAME}

# Compiling the library
$(LIBFT):
		make -C Libft/

# Compiling the graphics library
$(MINILIBX):
		make -C minilibx_macos/

# This won't run if the source files don't exist or are not modified.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -g -MD -c $< -o $@ -I./$(INCLS)
include $(wildcard *.d)

# Rule to remove all the object files and directory.
clean:
		rm -rf $(OBJ_DIR) $(OBJS) && make clean -C Libft/ && make clean -C minilibx_macos/

# Rule to remove everything that has been created by the makefile.
fclean: clean
		rm -rf $(PROGRAM) && make fclean -C Libft/ && make clean -C minilibx_macos/

# Rule to re-make everything.
re: 	fclean all
