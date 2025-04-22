CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
NAME = hsh
SRC = main.c utils.c execute.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

