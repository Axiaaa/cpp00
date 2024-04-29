NAME = 3310
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp getters_setters.cpp
OBJS = $(SRCS:.cpp=.o)	

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
