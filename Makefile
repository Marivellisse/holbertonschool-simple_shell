CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
NAME = hsh

all: $(NAME)

$(NAME): main.c main.h
	$(CC) $(CFLAGS) main.c -o $(NAME)

clean:
	rm -f $(NAME)

