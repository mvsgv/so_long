
NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra -I/usr/local/include
LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
#SEG = -fsanitize=address -g

SRC_PATH = ./srcs/
GNL_PATH = ./get_next_line/
LBFT_PATH = ./libft/
OBJ_DIR = ./obj/

SRC =   so_long

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