#ifndef AUTOMATON_H
# define AUTOMATON_H

# define ALPHABET_AUTOMATON "01"
# define GAMMA_FUNCTION {{2, 1}, {3, 0}, {0, 3}, {1, 2}}
# define END_NODE 0

# ifndef SLEEP_TIME
#  define SLEEP_TIME 1000
# endif

# define INVALID_ARGUMENT -42

# define TEXT_ATTRIB_SIZE 10
# define SELECTED "\e[1;5;33m"
# define NOT_SELECTED "\e[m"
# define CLEAR_WINDOW "clear"

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

bool	draw_automaton(char input);
char	prompt_for_symbol(void);

#endif
