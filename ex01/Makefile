NAME = 3310
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp
OBJS = $(SRC:.cpp=.o)	

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean re