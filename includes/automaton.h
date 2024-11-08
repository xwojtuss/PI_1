#ifndef AUTOMATON_H
# define AUTOMATON_H

# define ALPHABET_AUTOMATON "01"
# define END_NODE 0

# define SLEEP_TIME 1000000

# define INVALID_ARGUMENT -42

# ifdef WINDOWS
#  define CLEAR_WINDOW "cls"
# else
#  define TEXT_ATTRIB_SIZE 10
#  define SELECTED "\e[1;5;33m"
#  define NOT_SELECTED "\e[m"
#  define CLEAR_WINDOW "clear"
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

bool	draw_automaton(char input);
char	prompt_for_symbol(void);

#endif
