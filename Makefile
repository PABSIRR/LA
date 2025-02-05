CC=gcc
CFLAGS=-Wall -Wpedantic -Werror -O0 -fno-inline -fno-pie -std=c99

NAME=minibomb

.PHONY: clean run build

$(NAME): $(NAME).c
	docker run --rm -u "$(shell id -u):$(shell id -g)" -v "$(CURDIR):/app" -w /app buildpack-deps:14.04 $(CC) $(NAME).c -I. $(CFLAGS) -o $(NAME)

build: $(NAME)

clean:
	rm $(NAME)

run: build
	./$(NAME)
