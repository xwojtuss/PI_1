#include "automaton.h"

bool	is_rest_eof_newline()
{
	char	temp;
	bool	result;

	result = true;
	temp = 42;
	while (temp != '\n' && temp != EOF)
		temp = getchar();
}

char	prompt_for_symbol(void)
{
	char	result;
	int		bytes_read;

	while (true)
	{
		bytes_read = scanf("%c", &result);
		if (bytes_read == 1 && is_rest_eof_newline())
			return (is_rest_eof_newline(), result);
		is_rest_eof_newline();
		if (bytes_read == -1)
			exit(EXIT_FAILURE);
		else if (bytes_read != 1)
			exit(EXIT_SUCCESS);
		printf("Podaj symbol należący do alfabetu sigma\n");
	}
}

int	main(void)
{
	char	symbol;

	while (true)
	{
		symbol = prompt_for_symbol();
		// draw_automaton(symbol);
		// if (is_accepted())
		// 	break ;
		printf("%c\n", symbol);
	}
	return (EXIT_SUCCESS);
}
