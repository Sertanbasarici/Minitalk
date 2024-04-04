NAME = serverclient

CC = gcc
CFLAGS = -Wall -Wextra -Werror
printf= ft_printf/ft_printf.a

CLIENT = client
SERVER = server

all: ${SERVER} ${CLIENT}

${NAME}: ${SERVER} ${CLIENT}

${SERVER}:
	@${MAKE} -C ./ft_printf
	@${CC} ${CFLAGS} server.c ${printf} -o server

$(CLIENT):
	@${CC} ${CFLAGS} client.c ${printf} -o client

clean:
	@${MAKE} -C ./ft_printf fclean

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all clean fclean re