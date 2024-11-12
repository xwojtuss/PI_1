# zmienna odpowiedzialna za czas animacji w ms, po zmianie należy wykonać make re
CZAS_ANIMACJI_MS = 1000

# w przypadku braku clang można zmienić na gcc, cc, itp.
COMPILER = clang

CFLAGS = -g -D SLEEP_TIME=${CZAS_ANIMACJI_MS}

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
