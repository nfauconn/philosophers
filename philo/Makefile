NAME = philo
OBJ_DIR  = ./objs
CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread -g3 #-fsanitize=thread
INCLUDES = -I includes
COMP = ${CC} ${CFLAGS}
RM	 = rm -rf
SRCS = end.c error.c init.c main.c meal_loop.c parse.c simulation.c utils.c
OBJS = ${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

$(NAME): ${OBJS}
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}
	@echo "philo created"

all: ${NAME}

val: ${NAME}
	valgrind ./${NAME}

norm: ${NAME}
	norminette ${SRCS} includes/*.h ${LIBFT}

clean:
	@rm -rf ${OBJ_DIR}
	@echo "objs deleted"

fclean: clean
	@rm -rf ${NAME}
	@echo "program deleted"

re: fclean all

.PHONY: all clean fclean re
