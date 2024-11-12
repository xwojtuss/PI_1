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

	printf("Proszę podać następny (tylko jeden) symbol zawarty w alfabecie S{0; 1} (EOF sprawdza łańcuch): ");
	result = getchar();
	accepted = is_rest_eof_newline();
	if (accepted == 0)
	{
		printf("Podano więcej niż jeden symbol.\n");
		exit(EXIT_FAILURE);
	}
	else if (accepted == -42 || result == EOF)
		return (printf("\n"), -42);
	if (strchr(ALPHABET_AUTOMATON, result))
		return (result);
	printf("Symbol nie jest zawarty w alfabecie sigma.\n");
	exit(EXIT_FAILURE);
}