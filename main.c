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

int	main(int argc, char **argv)
{
	char	symbol;

if (argc > 2)
 return (EXIT_FAILURE);
else if (argc == 1)
{
  while (true)
	{
		symbol = prompt_for_symbol();
		// accepted = draw_automaton(symbol);
		// if (accepted)
		// 	break ;
		printf("%c\n", symbol);
	}
}
else
{
length = check_string(argv[1]);
 if (length = -42)
   return (EXIT_FAILURE)
  for (int i=0; i<length; i++)
{
    accepted = draw_automaton(argv[1][i]);
    sleep(SLEEP_TIME);
    system(CLEAR_WINDOW);
}
  if (accepted)
    printf("Zaakceptowany");
  else
    printf("Nie zaakceptowany");
}
	return (EXIT_SUCCESS);
}
