NAME = miniRT

FOLDER_SRCS = srcs
INCLUDES = includes
MLX = minilibx
LIBFTA = libft/libft.a

SRC = 	main.c \
		/parser/parser.c \
		/parser/utils.c \
		/parser/ft_splitf.c \
		/parser/parse_environment.c \
		/parser/parse_environment2.c \
		/parser/parse_objs.c \
		/parser/error_handler.c \
		/parser/get_next_line.c \
		/parser/get_next_line_utils.c \
		/parser/atof.c \
		/parser/parse_color.c \
		/parser/init.c \
		/parser/init2.c \
		/parser/free_scene.c \
		/parser/free_scene2.c \
		/parser/parse_vec.c \
		/parser/utils_lst.c \
		/vectors/get_vec.c \
		/vectors/utils_vec.c \
		/vectors/utils_vec2.c \
		/window/render.c \
		/window/trace.c \
		/vectors/matrix.c \
		/window/search_intersect.c \
		/window/intersect_sphere.c \
		/window/solvequadratic.c \
		/window/compute_light.c \
		/parser/parse_sqr.c \
		/parser/parse_triangle.c \
		/window/intersect_triangle.c \
		/parser/parse_cylinder.c \
		/window/intersect_cylinder.c \
		/window/save_bmp.c

SRCS = $(addprefix ${FOLDER_SRCS}/, ${SRC})

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L . -lmlx -framework OpenGL -framework AppKit 
CC = gcc
RM = rm -f

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS) 
		@make -s -C libft
		@$(CC) $(CFLAGS) $(LFLAGS) -I $(INCLUDES) $(LIBFTA) $(OBJS) -o $(NAME)

$(MLX_LIB):
		@make -C $(MLX)
		@mv $(MLX)/libmlx.dylib .

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
		$(RM) $(OBJS)
		@make clean -C $(MLX)
		make clean -C libft

fclean: clean
		$(RM) libmlx.dylib
		$(RM) $(NAME)
		make fclean -C libft

re: fclean all

.PHONY: all fclean clean re

