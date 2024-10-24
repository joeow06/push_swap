LIBFT = libft/libft.a
NAME = push_swap

SRC_DIR = src
CMD_DIR = cmds
OBJ_DIR = obj
INC_DIR = inc

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/errors.c $(SRC_DIR)/init_a.c \
      $(SRC_DIR)/init_b.c $(SRC_DIR)/stack_init.c $(SRC_DIR)/stack_utils.c \
      $(CMD_DIR)/push.c $(CMD_DIR)/rotate.c $(CMD_DIR)/sort_three.c \
      $(CMD_DIR)/reverse_rotate.c $(CMD_DIR)/sort_stacks.c $(CMD_DIR)/swap.c

INC = push_swap.h
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Create .o from .c file, store all object files in obj directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(CMD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Create subdirectories for object files
$(OBJ_DIR)/$(SRC_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)

$(OBJ_DIR)/$(CMD_DIR):
	mkdir -p $(OBJ_DIR)/$(CMD_DIR)

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build libft
$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re

