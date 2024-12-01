# TARGET
NAME = so_long

# ARGUMENTS
CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

# SO_LONG FILES
SRC_PATH = ./srcs/
SRCS = so_long \
		map \
		checkers \
		image \
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(C_FILES:.c=.o)

# LIBFT
LIBFT_PATH = ./functions/
LIBFT_SRCS = ft_putstr_fd \
            get_next_line \
            get_next_line_utils
LBFT_FILES = $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS:=.c))
LBFT_OBJ = $(LBFT_FILES:.c=.o)

# INCLUDES
INC_PATH = ./includes/
INCLUDES = -I$(INC_PATH) -I$(LIBFT_PATH)

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LBFT_OBJ) $(MLX) -o $(NAME)
	@echo "Compilation terminée : $(NAME)"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)
	@echo "Fichiers objets supprimés."

fclean: clean
	@rm -f $(NAME)
	@echo "Exécutable supprimé."

re: fclean all

.PHONY: all clean fclean re
