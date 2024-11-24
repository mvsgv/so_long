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



NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra -I/usr/local/include
LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
#SEG = -fsanitize=address -g

SRC_PATH = ./srcs/
GNL_PATH = ./get_next_line/
LBFT_PATH = ./libft/
OBJ_DIR = ./obj/

SRC =   pixel

LBFT =  #ft_strlen

GNL =   get_next_line \
        get_next_line_utils

C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c)) $(addprefix $(LBFT_PATH), $(LBFT:=.c)) $(addprefix $(GNL_PATH), $(GNL:=.c))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:=.o)) $(addprefix $(OBJ_DIR), $(LBFT:=.o)) $(addprefix $(OBJ_DIR), $(GNL:=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
    @$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_DIR)%.o: $(GNL_PATH)%.c | $(OBJ_DIR)
    @$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
    @$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(LBFT_PATH)%.c | $(OBJ_DIR)
    @$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
    @mkdir -p $(OBJ_DIR)

clean:
    @rm -rf $(OBJ_DIR)

fclean: clean
    @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
