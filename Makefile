COMPILER = clang

CFLAGS = -Wall -Wextra -Werror

NAME = automaton

INCLUDES = -Iincludes

SRCS_FOLDER = sources/
SRCS_FILES = main.c

SRCS = ${addsuffix ${SRCS_FOLDER}, ${SRCS_FILES}}

OBJECTS_FOLDER = objects/
OBJECTS_FILES = ${SRCS:.c=.o}

OBJECTS = ${addsuffix ${OBJECTS_FOLDER}, ${OBJECTS_FILES}}

all: ${NAME}

${NAME}: ${OBJECTS}

%.o: %.c
	${COMPILER} ${CFLAGS} -c $< -o $@ ${INCLUDES}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean make all re
