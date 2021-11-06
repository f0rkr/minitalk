SERVER_NAME=server
CLIENT_NAME=client
SERVER=srcs/server.c
CLIENT=srcs/client.c
UTILS=srcs/utils.c
INCLUDES=./includes/
CC=gcc
FLAGS=-Wall -Werror -Wextra

all : BUILD

BUILD: $(SERVER) $(CLIENT)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(UTILS) $(SERVER) -o $(SERVER_NAME)
	@$(CC) $(FLAGS) -I $(INCLUDES) $(UTILS) $(CLIENT) -o $(CLIENT_NAME)

clean:
	@rm -rf $(SERVER_NAME)
	@rm -rf $(CLIENT_NAME)

fclean: clean

re: all
