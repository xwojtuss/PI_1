#include "automaton.h"

char	get_letter(void)
{
	char	letter;

	letter = getchar();
	if (letter == EOF)
	{
		printf("\nWychodzenie...\n");
		exit(EXIT_SUCCESS);
	}
	return (letter);
}

/*
Flushes the input buffer, while looking
if the rest of the characters are only newlines or EOF
*/
bool	is_rest_eof_newline(void)
{
	char	temp;
	bool	result;

	result = true;
	temp = 42;
	while (temp != '\n')
	{
		temp = get_letter();
		if (temp != '\n')
			result = false;
	}
    return (result);
}

char	prompt_for_symbol(void)
{
	char	result;

	while (true)
	{
		printf("Proszę podać następny (tylko jeden) symbol zawarty w alfabecie S{0; 1} > ");
		result = get_letter();
		if (is_rest_eof_newline() && strchr(ALPHABET_AUTOMATON, result))
			return (result);
	}
	return (result);
}