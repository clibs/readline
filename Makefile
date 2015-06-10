CFLAGS := -Wall -pedantic -std=c99

test: readline.c test.c
	@$(CC) $^ $(CFLAGS) -o $@
	@./test

.PHONY: test
