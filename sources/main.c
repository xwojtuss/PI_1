#include "automaton.h"

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
		printf("WRONG ARGC COUNT MESSAGE\n");//placeholder
		return (EXIT_FAILURE);
	}
	else if (argc == 1)
	{
		symbol = -42 + '0';
		while (true)
		{
			system(CLEAR_WINDOW);
			accepted = draw_automaton(symbol - '0');
			if (accepted && symbol != -42 + '0')
				break ;
			printf("NOT ACCEPTED MESSAGE\n");//placeholder
			symbol = prompt_for_symbol();
		}
	}
	else
	{
		length = check_string(argv[1]);
		if (length == INVALID_ARGUMENT)
			return (EXIT_FAILURE);
		accepted = draw_automaton(-42);
		if (length > 0)
		{
			usleep(SLEEP_TIME);
			system(CLEAR_WINDOW);
		}
		for (int i = 0; i < length; i++)
		{
			accepted = draw_automaton(argv[1][i] - '0');
			usleep(SLEEP_TIME);
			system(CLEAR_WINDOW);
		}
		if (!accepted)
		{
			printf("NOT ACCEPTED MESSAGE\n");//placeholder
			return (EXIT_SUCCESS);
		}
	}
	printf("ACCEPTED MESSAGE\n");//placeholder
	return (EXIT_SUCCESS);
}
