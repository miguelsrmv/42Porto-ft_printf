/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:08:54 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/26 20:55:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	printf("*");
	fflush(stdout);
*/

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{

	printf("Teste 1: %i.\n", 5000);
	ft_printf("Teste 1a: %i.\n", 5000);
	printf("Teste 2: % i.\n", 5000);
	ft_printf("Teste 2a: % i.\n", 5000);
	printf("Teste 3: %5i.\n", 5000);
	ft_printf("Teste 3a: %5i.\n", 5000);
	printf("Teste 4: %1i.\n", 5000);
	ft_printf("Teste 4a: %1i.\n", 5000);
	printf("Teste 5: %10i.\n", 5000);
	ft_printf("Teste 5a: %10i.\n", 5000);
	printf("Teste 6: %.5i.\n", 5000);
	ft_printf("Teste 6a: %.5i.\n", 5000);
	printf("Teste 7: %.1i.\n", 5000);
	ft_printf("Teste 7a: %.1i.\n", 5000);
	printf("Teste 8: %.10i.\n", 5000);
	ft_printf("Teste 8a: %.10i.\n", 5000);
	printf("Teste 9: %5.5i.\n", 5000);
	ft_printf("Teste 9a: %5.5i.\n", 5000);
	printf("Teste 10: %10.15i.\n", 5000);		// Width é tamanho total da string
	ft_printf("Teste 10a: %10.15i.\n", 5000); // Width é tamanho total da string
	printf("Teste 11: %15.10i.\n", 5000);		// Precision é tamanho da parte numerica
	ft_printf("Teste 11a: %15.10i.\n", 5000); // Precision é tamanho da parte numerica
	printf("Teste 12: %-i.\n", 5000);
	ft_printf("Teste 12a: %-i.\n", 5000);
	printf("Teste 13: %+i.\n", 5000);
	ft_printf("Teste 13a: %+i.\n", 5000);
	printf("Teste 14: % i.\n", 5000);
	ft_printf("Teste 14a: % i.\n", 5000);
	printf("Teste 15: %0i.\n", 5000);
	ft_printf("Teste 15a: %0i.\n", 5000);

/*
	printf("Teste 1: %i.\n", -5000);
	ft_printf("Teste 1: %i.\n", -5000);
	printf("Teste 2: % i.\n", -5000);
	ft_printf("Teste 2: % i.\n", -5000);
	printf("Teste 3: %5i.\n", -5000);
	ft_printf("Teste 3: %5i.\n", -5000);
	printf("Teste 4: %1i.\n", -5000);
	ft_printf("Teste 4: %1i.\n", -5000);
	printf("Teste 5: %10i.\n", -5000);
	ft_printf("Teste 5: %10i.\n", -5000);
	printf("Teste 6: %.5i.\n", -5000);
	ft_printf("Teste 6: %.5i.\n", -5000);
	printf("Teste 7: %.1i.\n", -5000);
	ft_printf("Teste 7: %.1i.\n", -5000);
	printf("Teste 8: %.10i.\n", -5000);
	ft_printf("Teste 8: %.10i.\n", -5000);
	printf("Teste 9: %5.5i.\n", -5000);
	ft_printf("Teste 9: %5.5i.\n", -5000);
	printf("Teste 10: %10.15i.\n", -5000);		// Width é tamanho total da string
	ft_printf("Teste 10: %10.15i.\n", -5000); // Width é tamanho total da string
	printf("Teste 11: %15.10i.\n", -5000);		// Precision é tamanho da parte numerica
	ft_printf("Teste 11: %15.10i.\n", -5000); // Precision é tamanho da parte numerica
	printf("Teste 12: %-i.\n", -5000);
	ft_printf("Teste 12: %-i.\n", -5000);
	printf("Teste 13: %+i.\n", -5000);
	ft_printf("Teste 13: %+i.\n", -5000);
	printf("Teste 14: % i.\n", -5000);
	ft_printf("Teste 14: % i.\n", -5000);
	printf("Teste 15: %0i.\n", -5000);
	ft_printf("Teste 15: %0i.\n", -5000);


	printf("Teste 1: %-i.\n", -5000);
	printf("Teste 2: %- i.\n", -5000);
	printf("Teste 3: %-5i.\n", -5000);
	printf("Teste 4: %-1i.\n", -5000);
	printf("Teste 5: %-10i.\n", -5000);
	printf("Teste 6: %-.5i.\n", -5000);
	printf("Teste 7: %-.1i.\n", -5000);
	printf("Teste 8: %-.10i.\n", -5000);
	printf("Teste 9: %-5.5i.\n", -5000);
	printf("Teste 10: %-10.15i.\n", -5000);		// Width é tamanho total da string
	printf("Teste 11: %-15.10i.\n", -5000);		// Precision é tamanho da parte numerica
	printf("Teste 12: %-i.\n", -5000);
	printf("Teste 13: %-+i.\n", -5000);
	printf("Teste 14: %- i.\n", -5000);

	printf("Teste 1: %i.\n", -5000);
	printf("Teste 3: %+5i.\n", 5000);
	printf("Teste 4: %+1i.\n", 5000);
	printf("Teste 5: %+10i.\n", 5000);
	printf("Teste 6: %+.5i.\n", 5000);
	printf("Teste 7: %+.1i.\n", 5000);
	printf("Teste 8: %+.10i.\n", 5000);
	printf("Teste 9: %+5.5i.\n", 5000);
	printf("Teste 10: %+10.15i.\n", 5000);		// Width é tamanho total da string
	printf("Teste 11: %+15.10i.\n", 5000);		// Precision é tamanho da parte numerica
	printf("Teste 12: %+-i.\n", 5000);
	printf("Teste 13: %+i.\n", 5000);
	printf("Teste 15: %+0i.\n", 5000);		
*/
/* 
	STRING TESTS
	int	result;
	
 	result = ft_printf("#1 Ola %15.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
 	result = printf("#1 Ola %15.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#2A Ola %-5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#2A Ola %-5s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#2B Ola %-10s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#2B Ola %-10s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#2C Ola %-20s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#2C Ola %-20s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#3 Ola %5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#3 Ola %5s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#4 Ola %10s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#4 Ola %10s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#5 Ola %20s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#5 Ola %20s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#6 Ola %.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#6 Ola %.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#7 Ola %.10s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#7 Ola %.10s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#8 Ola %.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#8 Ola %.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#9 Ola %10.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#9 Ola %10.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#10 Ola %-10.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#10 Ola %-10.15s.", "Jamaicano");
	printf("Result: %i\n\n", result);

	result = ft_printf("#11 Ola %-10.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
	result = printf("#11 Ola %-10.5s.", "Jamaicano");
	printf("Result: %i\n\n", result);
 */
	
/*
	ft_printf("Here is a number", 5);
	printf("\n");
	printf("Here is a number: %8i.\n", 54321);			/// 3 spaces + N
	printf("Here is a number: %08i.\n", 54321);			/// 3 zeros + N
	printf("Here is a number: %.8i.\n", 54321);			/// 3 zeros + N
	printf("Here is a number: %-8i.\n", 54321);			/// N + 3 spaces
	printf("Here is a number: %- 8i.\n", 54321);		/// space + N + 2 spaces
	printf("Here is a number: %08i.\n", 54321);			///	3 zeros + N
	printf("Here is a number: %+8i.\n", 54321);			///	2 spaces + '+' + N
	printf("Here is a number: %0+8i.\n", 54321);		///	´00´ + '+' + N	
	printf("%s, %s, %s.\n", ft_itoa(123), ft_itoa(-123), ft_itoa(0));
*/
}



/*

- (minus)	Left-align the output of this placeholder. (The default is to right-align the output.)

+ (plus) A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a
sign is used only for negative numbers.  A + overrides a space if both are used.

0 (zero)	When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces.)
For example, printf("%4X",3) produces    3, while printf("%04X",3) produces 0003.
IGNORAR SE HOUVER MINUS


# (hashtag)
Alternate form:
For g and G types, trailing zeros are not removed.
For f, F, e, E, g, G types, the output always contains a decimal point.
For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers. << único que interessa???


' '    (a  space)  A blank should be left before a positive number (or empty string) produced by a signed conversion.
IGNORAR SE HOUVER PLUS

. (dot)


Field minimum width

*/