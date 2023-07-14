CC = cc
CFLAGS = -Wall -Wextra -Werror #-pthread -fsanitize=thread -g3
NAME = philo
SRCS = philosophers.c helpers_1.c philo_creation.c acts.c checks.c sim.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: all clean fclean re
