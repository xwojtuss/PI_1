COMPILER = clang

CFLAGS = -Wall -Wextra -Werror

NAME = automaton

INCLUDES = -Iincludes

SRCS_FOLDER = sources/
SRCS_FILES = main.c read_from_stdin.c draw.c

SRCS = ${addprefix ${SRCS_FOLDER}, ${SRCS_FILES}}

OBJECTS_FOLDER = objects/
OBJECTS_FILES = ${SRCS_FILES:.c=.o}

OBJECTS = ${addprefix ${OBJECTS_FOLDER}, ${OBJECTS_FILES}}

all: ${NAME}

${NAME}: ${OBJECTS}
	${COMPILER} ${CFLAGS} ${OBJECTS} -o $@ ${INCLUDES}

${OBJECTS_FOLDER}%.o: ${SRCS_FOLDER}%.c
	${COMPILER} ${CFLAGS} -c $< -o $@ ${INCLUDES}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean make all re
