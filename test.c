
#include <stdio.h>
#include "ft_printf.h"

int	main (void)
{
	int	result;

	result = ft_printf("Ola %c%c%c %%%% %s\n", 'o', 'l', 'a', "ola");
	printf("Result: %i\n", result);
	printf("\n");
 	result = printf("Ola %c%c%c %%%% %s\n", 'o', 'l', 'a', "ola");
 	printf("Result: %i\n", result);
}
