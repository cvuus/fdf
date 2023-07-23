SRCS	= fdf.c\
	./getnextline/get_next_line_bonus.c\
	./getnextline/get_next_line_utils_bonus.c\
	./sources/input.c\
	./sources/project.c\
	./sources/initalizer.c\
	./sources/coloring.c\
	./sources/key_hook.c\
	./sources/graphics.c\
	./sources/graphics_utils.c\
	./sources/wu_line_algorithm.c\
	./sources/wu_line_algorithm_utils.c\
	./sources/fdf_utils.c

BONUSSRCS	= fdf.c\
	./getnextline/get_next_line_bonus.c\
	./getnextline/get_next_line_utils_bonus.c\
	./sources/input.c\
	./sources/project.c\
	./sources/initalizer.c\
	./sources/coloring.c\
	./sources/graphics.c\
	./sources/graphics_utils.c\
	./sources/wu_line_algorithm.c\
	./sources/wu_line_algorithm_utils.c\
	./sources/key_hook_bonus.c\
	./sources/key_hook_zoom.c\
	./sources/key_hook_rotation.c\
	./sources/key_hook_translation.c\
	./sources/fdf_utils.c

NAME = fdf

LIBFT = ./libft/libft.a

PRINTF = ./libftprintf/libftprintf.a

GLFW = -Iinclude -lglfw3

MLX = ./MLX42/build/libmlx42.a

HEADER = -I./includes.fdf.h

OBJS = ${SRCS:.c=.o}

BONUSOBJS = ${BONUSSRCS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -fsanitize=address -framework Cocoa -framework OpenGL -framework IOKit

ifdef ADD_BONUS
ALLFILES = ${BONUSOBJS}
else 
ALLFILES = ${OBJS}
endif


.c.o:
	@${CC} -c $< -o ${<:.c=.o} -I ${LIBFT}

all: ${LIBFT} ${PRINTF} ${NAME}
	
${LIBFT}:
	@echo "\033[33mCreating libft.a ..."
	@make -C ./libft
	@echo "\033[32mCONGRATULATIONS libft created\n"

${PRINTF}:
	@echo "\033[33mCreating libftprintf.a ..."
	@make -C ./libftprintf
	@echo "\033[32mCONGRATULATIONS libftprintf created\n"

${MLX}:
	@echo "\033[33mCreating libmlx.a ...\033[0m"
	@cd MLX42 && pwd && \
		rm -rf build && \
		cmake -B build && \
		make -C build -j4
	@echo "\033[32m\n\n\n\nCONGRATULATIONS MLX42 created\n"

${NAME}: ${ALLFILES} ${LIBFT} ${MLX}
	@echo "\033[33mCompiling fdf..."
	@${CC} ${FLAGS} ${HEADER} ${LIBFT} ${PRINTF} ${MLX} ${GLFW} ${ALLFILES}  -o ${NAME}
	@echo "\033[32m\nCompiling fdf done \n ** Now you can use ./fdf to start the program **\033[0m"


bonus: clean
	@echo "\033[33m Compiling fdf with bonus now...\n\n"
	${MAKE} ADD_BONUS=1

clean:
	${RM} ${OBJS}

fclean: clean
	make fclean -C ./libft
	make fclean -C ./libftprintf
	make clean	-C ./MLX42/build
	${RM} ${NAME}

re: fclean all