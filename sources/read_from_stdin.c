#include "automaton.h"

/*
Flushes the input buffer, while looking
if the rest of the characters are only newlines or EOF
*/
short	is_rest_eof_newline(void)
{
	char	temp;
	short	result;

	result = 1;
	temp = 42;
	while (temp != '\n')
	{
		temp = getchar();
		if (temp == EOF)
			return (-42);
		if (temp != '\n')
			result = 0;
	}
    return (result);
}

char	prompt_for_symbol(void)
{
	char	result;
	short	accepted;

	printf("Please add next (only one) symbol that is part of alphabet S{0; 1} (EOF checks string): ");
	result = getchar();
	accepted = is_rest_eof_newline();
	if (accepted == 0)
	{
		printf("Inputed more than one symbol.\n");
		exit(EXIT_FAILURE);
	}
	else if (accepted == -42 || result == EOF)
		return (printf("\n"), -42);
	if (strchr(ALPHABET_AUTOMATON, result))
		return (result);
	printf("Symbol is not a part of alpabet sigma.\n");
	exit(EXIT_FAILURE);
}
