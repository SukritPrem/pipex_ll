


NAME := pipex

SRC := main.c all_process.c error_free.c free_1.c free.c init_lst.c utils.c utils_1.c error_free_1.c all_process_1.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) ./libft/libft.a $(OBJ) -o $(NAME)

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f ./libft/libft.a
	rm -f pipex

re : fclean all

.PHONY: all clean fclean re