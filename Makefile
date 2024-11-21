NAME 			= so_long

CC 				= cc

CFLAGS 			= -Werror -Wall -Wextra -g

MLX_PATH		= mlx/

MLX_FLAGS 		= -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

RM 				= rm -rf

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRCS 			= so_long.c

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)			

#for linking the required libraries and frameworks:
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

.PHONY: fclean re clean all