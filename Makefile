NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER_SRC = server.c
CLIENT_SRC = client.c
UTILS_SRC = utils_func.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
 $(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
 $(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(NAME_CLIENT)

clean:
 $(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)

fclean: clean
 $(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re