#include "ft_boolean.h"
#include <stdio.h>

int	main(int c, char **v)
{
	
	t_bool var = TRUE;

	if (v[1][0] == 'n')
		var = FALSE;
	printf("== %s ==\n", var == TRUE ? "TRUE":"FALSE");
}
