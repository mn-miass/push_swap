#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = parsing_bonus(argc, argv);
	b = NULL;
	check_bonus(&a, &b);
	return (0);
}
