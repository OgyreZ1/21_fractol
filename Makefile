SRCS	=	./src/colors.c ./src/events.c ./src/main.c ./src/mandelbrot.c ./src/tools.c

OBJ_SRC = ${SRCS:.c=.o}

CC = gcc

NAME = fractol

REM = rm -f

HEADER = ./src/fractol.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

%.o:	%.c ${HEADER}
			${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ_SRC}
			${CC} ${FLAGS} ${OBJ_SRC} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	${REM} ${OBJ_SRC} ${OBJ_B}

fclean: clean
	${REM} ${OBJ_SRC} ${OBJ_B} ${NAME} ${BONUS}
	
re: fclean all