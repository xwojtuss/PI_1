#include "automaton.h"

void	print_usage(void)
{
	printf("Wywołanie: ./automaton [łańcuch wejściowy]\n");
	printf("Łańcuch wejściowy musi składać się z symboli z alfabetu {0, 1}, łańcuch pusty epsilon także jest akceptowalny\n");
	printf("Jeśli argument nie zostanie podany, program będzie pytał o kolejne symbole, dopóki nie dojdziemy do stanu końcowego.\n");
}

int	check_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!strchr(ALPHABET_AUTOMATON, string[i]))
			return (INVALID_ARGUMENT);
		i++;
	}
	return (i);
}

int get_next_selected(int current, int input);

int	main(int argc, char **argv)
{
	char	symbol;
	int		length;
	bool	accepted;

	if (argc > 2)
	{
		printf("Zła ilość argumentów wywołania\n");
		print_usage();
		return (EXIT_FAILURE);
	}
	else if (argc == 1)
	{
		symbol = -42 + '0';
		while (true)
		{
			system(CLEAR_WINDOW);
			accepted = draw_automaton(symbol - '0');
			symbol = prompt_for_symbol();
			if (symbol == -42 && !accepted)
			{
				printf("Łańcuch nie został zaakceptowany, nie dotarto do stanu końcowego.\n");
				return (EXIT_SUCCESS);
			}
			else if (symbol == -42)
				return (printf("Łańcuch zaakceptowany, dotarto do stanu końcowego.\n"), EXIT_SUCCESS);
		}
	}
	else
	{
		length = check_string(argv[1]);
		if (length == INVALID_ARGUMENT)
		{
			printf("Łańcuch %s zawiera symbole spoza alfabetu.\n", argv[1]);
			print_usage();
			return (EXIT_FAILURE);
		}
		system(CLEAR_WINDOW);
		accepted = draw_automaton(-42);
		for (int i = 0; i < length; i++)
		{
			usleep(SLEEP_TIME * 1000);
			system(CLEAR_WINDOW);
			accepted = draw_automaton(argv[1][i] - '0');
		}
		if (!accepted)
		{
			printf("Łańcuch %s nie został zaakceptowany, nie dotarto do stanu końcowego.\n", argv[1]);
			return (EXIT_SUCCESS);
		}
	}
	printf("Łańcuch %s zaakceptowany, dotarto do stanu końcowego.\n", argv[1]);
	return (EXIT_SUCCESS);
}
