GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILE = s_main.c \
		s_window.c \
		s_character.c \
		s_print_map.c \
		s_parsing_map.c \
		s_clear.c \
		s_enemie.c \
		s_utils_map.c \
		s_hook.c \
		s_check_map.c \


LIBFT = libft/libft.a
RM = rm -f
CC = cc
CFLAGS	= -Wall -Werror -Wextra -ggdb
AR	= ar rc

NAME = so_long

SRCS = ${FILE}

OBJS = ${SRCS:.c=.o}

all:	${NAME}
	@echo "${GREEN}Compilation successful !${RESET}"

.c.o:
	@${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

${LIBFT}:	
	@echo "${GREEN}Compilation LIBFT...${RESET}"
	@make -s -C libft bonus

${NAME}:	${OBJS} ${LIBFT} ${MLX}
	@echo "${GREEN}Compilation SO_LONG...${RESET}"
	@${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME} ${LIBFT}

clean:
	@echo "${RED}Cleaning...${RESET}"
	@make -s -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${LONG}

re: fclean all
