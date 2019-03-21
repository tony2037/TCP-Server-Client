CC = gcc
CFLAGS += -g -Wall

all: server client
server: server.c rio.c
	$(CC) $(CFLAGS) $^ -o $@
client: client.c rio.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) server client
