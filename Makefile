NAME 			= so_long

CC 				= gcc

CFLAGS 			= -Werror -Wall -Wextra 


# MLX_FLAGS 		= -L/usr/local/lib -lmlx -I/usr/local/include -framework OpenGL -framework AppKit 
LIBMLX = -L/path/to/minilibx -lmlx

RM 				= rm -rf

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRCS 			= so_long.c \

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

#for linking the required libraries and frameworks:
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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