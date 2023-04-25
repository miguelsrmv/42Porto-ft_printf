
#include <stdio.h>
#include "ft_printf.h"

int	main (void)
{
	/*
	int	result;

	result = ft_printf("Ola %c%c%c %%%% %s\n", 'o', 'l', 'a', "ola");
	printf("Result: %i\n", result);
	printf("\n");
 	result = printf("Ola %c%c%c %%%% %s\n", 'o', 'l', 'a', "ola");
 	printf("Result: %i\n", result);
	*/
	char *pointer = "little";
	ft_printf("Here is a number-%4s-and a-%s-word.\n", "number", pointer);
	printf("\n");
	printf("Here is a number-%4s-and a-%s-word.\n", "number", pointer);
}
