CC=gcc
CFLAGS=-Wall -Wpedantic -Werror -O0 -fno-inline -fno-pie -std=c99
NAME=minibomb

$(NAME): $(NAME).c
	$(CC) $(NAME).c -I. $(CFLAGS) -o $(NAME)

clean:
	rm $(NAME)