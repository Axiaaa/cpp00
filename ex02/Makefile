NAME = emploi_de_mes_reves
CC = clang++
# CFLAGS = -Wall -Wextra -Werror
SRC = Account.cpp \
		tests.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(ONJS)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean re