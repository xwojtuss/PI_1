#include "automaton.h"

int get_next_selected(int current, int input)
{
	int	nodes[4][2] = GAMMA_FUNCTION;
	return (nodes[current][input]);
}

bool	draw_automaton(char input)
{
    static int selected;
	char	nodes[4][15] = {NOT_SELECTED, NOT_SELECTED, NOT_SELECTED, NOT_SELECTED};

	if (input == -42)
		selected = 0;
	else
		selected = get_next_selected(selected, input);
	strcpy(nodes[selected], SELECTED);
	printf("%s____________     %s1     ____________\n" NOT_SELECTED, nodes[0], nodes[1]);
	printf("%s| ________ |%s<----------|          |\n" NOT_SELECTED, nodes[0], nodes[1]);
	printf("%s| |  " NOT_SELECTED "q0%s  | |           %s|    " NOT_SELECTED "q1%s    |\n" NOT_SELECTED, nodes[0], nodes[0], nodes[1], nodes[1]);
	printf("%s| |______| |---------->%s|          |\n" NOT_SELECTED, nodes[0], nodes[1]);
	printf("%s|__________|     1     %s|__________|\n" NOT_SELECTED, nodes[0], nodes[1]);
	printf("    %s| %s/|\\                  %s| %s/|\\\n" NOT_SELECTED, nodes[0], nodes[2], nodes[1], nodes[3]);
	printf("    %s|  %s|                   %s|  %s|\n" NOT_SELECTED, nodes[0], nodes[2], nodes[1], nodes[3]);
	printf("  %s0 |  %s| 0               %s0 |  %s| 0\n" NOT_SELECTED, nodes[0], nodes[2], nodes[1], nodes[3]);
	printf("    %s|  %s|                   %s|  %s|\n" NOT_SELECTED, nodes[0], nodes[2], nodes[1], nodes[3]);
	printf("   %s\\|/ %s|                  %s\\|/ %s|\n" NOT_SELECTED, nodes[0], nodes[2], nodes[1], nodes[3]);
	printf("%s____________     %s1     ____________\n" NOT_SELECTED, nodes[2], nodes[3]);
	printf("%s|          |%s<----------|          |\n" NOT_SELECTED, nodes[2], nodes[3]);
	printf("%s|    " NOT_SELECTED "q2%s    |           %s|    " NOT_SELECTED "q3%s    |\n" NOT_SELECTED, nodes[2], nodes[2], nodes[3], nodes[3]);
	printf("%s|          |---------->%s|          |\n" NOT_SELECTED, nodes[2], nodes[3]);
	printf("%s|__________|     1     %s|__________|\n" NOT_SELECTED, nodes[2], nodes[3]);
	if (selected == END_NODE)
		return (true);
	return (false);
}