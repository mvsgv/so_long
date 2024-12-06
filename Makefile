# TARGET
NAME = so_long

# ARGUMENTS
CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit

# SO_LONG FILES
SRC_PATH = ./srcs/
SRCS = main \
		map \
		checkers \
		image \
		create \
		ending \
		moving \
		utils \
		find_wall
C_FILES = $(addprefix $(SRC_PATH), $(SRCS:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRCS:=.o))

# LIBFT
LIBFT_PATH = ./functions/
LIBFT_SRCS = ft_putstr_fd \
            get_next_line \
			ft_split \
			get_next_line_utils \
			ft_strlen \
			ft_strncmp
LIBFT_FILES = $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS:=.c))
LIBFT_OBJ = $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS:=.o))

#INCLUDES
INC_PATH = ./includes/
INCLUDES = -I$(INC_PATH) -I$(LIBFT_PATH)

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_OBJ) $(MLX) -o $(NAME)
	@echo "Compilation terminée : $(NAME)"

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LIBFT_OBJ)
	@echo "Fichiers objets supprimés."

fclean: clean
	@rm -f $(NAME)
	@echo "Exécutable supprimé."

re: fclean all

.PHONY: all clean fclean re
