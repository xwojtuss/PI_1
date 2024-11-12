# variable responsible for animation time, after changed run "make re"
SLEEP_TIME = 1000

COMPILER = clang

CFLAGS = -g -D SLEEP_TIME=${SLEEP_TIME}

NAME = automat

INCLUDES = -Iincludes

SRCS_FOLDER = sources/
SRCS_FILES = main.c read_from_stdin.c draw.c

SRCS = ${addprefix ${SRCS_FOLDER}, ${SRCS_FILES}}

OBJECTS_FOLDER = sources/
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
