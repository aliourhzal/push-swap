NAME = push_swap

SRC = main.c big-sort.c mini-sort.c stack_storing.c indexing.c op_funcs.c push_funcs.c selection-sort.c basic_checks.c ft_atoi.c ft_putnbr.c ft_split.c ft_strdup.c ft_strjoin.c

BNS = checker

BNSSRC = checker.c basic_checks.c stack_storing.c op_funcs.c push_funcs.c ft_split.c ft_strdup.c ft_strjoin.c ft_atoi.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC) push_swap.h
	cc -Wall -Werror -Wextra $(SRC) -o $@

bonus: $(BNS)

$(BNS):	$(BNSSRC) push_swap.h get_next_line/get_next_line.h
	cc -Wall -Werror -Wextra $(BNSSRC) -o $@

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(BNS)

re: fclean all