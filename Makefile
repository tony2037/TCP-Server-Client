CC = gcc
CFLAGS += -g -Wall

server: server.c
	$(CC) $(CFLAGS) $^ -o $@
all: server
clean:
	$(RM) server
