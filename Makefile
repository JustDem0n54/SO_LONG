GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILE = main.c \
		window.c \

LIBFT = libft/libft.a
RM = rm -f
CC = cc
CFLAGS	= -Wall -Werror -Wextra -ggdb
AR	= ar rc

NAME = so_long

SRCS = ${FILE}

OBJS = ${SRCS:.c=.o}

.c.o:
	@${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

${LIBFT}:	
	@echo "${GREEN}Compilation LIBFT...${RESET}"
	@make -s -C libft bonus

${NAME}:	${OBJS} ${LIBFT} ${MLX}
	@echo "${GREEN}Compilation SO_LONG...${RESET}"
	@${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME} ${LIBFT}

all:	${NAME}
	@echo "${GREEN}Compilation successful !${RESET}"

clean:
	@echo "${RED}Cleaning...${RESET}"
	@make -s -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${LONG}

re: fclean all
