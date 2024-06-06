


NAME := pipex

SRCS := main.c all_process.c error_free.c free_1.c free.c init_lst.c utils.c utils_1.c error_free_1.c all_process_1.c
 
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

all: $(NAME)

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -Llibft -Ilibft   -c $< -o $@

$(NAME) : $(OBJS)
	make  -C libft
	$(CC) $(CFLAGS)  $(OBJS) ./libft/libft.a -o $(NAME)

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f ./libft/libft.a
	rm -f pipex

re : fclean all

.PHONY: all clean fclean re
