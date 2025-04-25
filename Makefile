CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
NAME = hsh

SRC = main.c utils.c functions.c execute.c find_in_path.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(NAME) *.o

