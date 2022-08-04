NAME = push_swap

SRC = push_swap.c tools/check_error.c tools/ft_atoi.c tools/array.c\
	tools/indexation.c tools/lists.c tools/markup.c tools/a_to_b.c\
	tools/instructions1.c tools/tools.c tools/b_to_a.c tools/tools1.c\
	tools/ft_split.c tools/parsing.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(OBJ) push_swap.o 
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅🤖✅"

all: $(NAME)

$(B_NAME): $(OBJ) $(B_OBJ)
	cc $(CFLAGS) $(OBJ) $(B_OBJ) -o $(B_NAME)

bonus: $(B_NAME)

clean:
	@rm -rf $(OBJ) $(B_OBJ) checker_bonus.o push_swap.o

fclean: clean
	@rm -rf $(NAME) $(B_NAME)
	@echo "🚮🚮🚮"

re: fclean all
