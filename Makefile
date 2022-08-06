SRCS	=	./src/colors.c ./src/events.c ./src/main.c ./src/mandelbrot.c ./src/tools.c ./src/julia.c ./src/burning_ship.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

all:		$(NAME)

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./mlx
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./mlx -framework OpenGL -framework AppKit

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all



