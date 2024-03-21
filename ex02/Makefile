NAME = emploi_de_mes_reves
CC = clang++
# CFLAGS = -Wall -Wextra -Werror
SRC = Account.cpp \
		tests.cpp
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -I. $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean re