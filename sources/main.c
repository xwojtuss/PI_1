#include "automaton.h"

void	print_usage(void)
{
	printf("Usage: ./automaton [string]\n");
	printf("The string must consist of symbols: {0, 1}, an empty epsilon string is also acceptable\n");
	printf("If the string is not provided, the program will ask for symbols one by one, until EOF is reached.\n");
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
		printf("Wrong argument count\n");
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
				printf("String not accepted, did not reach the final state.\n");
				return (EXIT_SUCCESS);
			}
			else if (symbol == -42)
				return (printf("String accepted.\n"), EXIT_SUCCESS);
		}
	}
	else
	{
		length = check_string(argv[1]);
		if (length == INVALID_ARGUMENT)
		{
			printf("String %s consists of symbols not from alphabet sigma.\n", argv[1]);
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
			printf("String %s not accepted, did not reach the final state.\n", argv[1]);
			return (EXIT_SUCCESS);
		}
	}
	printf("String %s accepted.\n", argv[1]);
	return (EXIT_SUCCESS);
}
