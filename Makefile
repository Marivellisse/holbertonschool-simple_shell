CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
NAME = hsh
SRC = main.c utils.c execute.c find_in_path.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

