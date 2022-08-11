NAME = push_swap

B_NAME = checker

SRC = tools/check_error.c tools/ft_atoi.c tools/ft_split.c\
	tools/indexation.c tools/lists.c tools/markup.c tools/a_to_b.c\
	tools/instructions.c tools/tools.c tools/b_to_a.c tools/tools1.c\
	tools/parsing.c tools/ft_strjoin.c

B_SRC = tools/get_next_line.c checker_bonus.c tools/tools_bonus.c\
	tools/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

CFLAGS = -D BUFFER_SIZE=42 -Wall -Wextra -Werror -g

$(NAME): $(OBJ) push_swap.o 
	@cc $(CFLAGS) $(OBJ) push_swap.o -o $(NAME)
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
