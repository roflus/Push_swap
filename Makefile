# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rharing <rharing@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/05 12:34:20 by rharing       #+#    #+#                  #
#    Updated: 2022/05/16 15:29:54 by rharing       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./Libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -Wall -Wextra -Werror
INC = -I ./Includes
SRC = ./Src/push_swap.c ./Src/error_function.c ./Src/create_list.c ./Src/operations.c \
		./Src/utils_list.c ./Src/small_sort.c ./Src/sort_check.c ./Src/argument_check.c \
		./Src/insert_values.c ./Src/sort_og_position.c ./Src/big_sort.c ./Src/small_sort_utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

%.o: %.c
	gcc $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re