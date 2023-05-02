/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 14:39:56 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_printf_string(char *string, t_flags *flag)
{
	char	*substr;
	int		count;

	if (!string)
		substr = ft_substr("(nullA", 0, 6);
	else
		substr = ft_substr(string, 0, flag->precision);
	if (!substr)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if (flag->precision == 0ls)
		flag->precision = ft_strlen(substr);
	printf("\n** 2 Substr is %s, flag-width is %i, flag-precision is %i, strlen is %i **\n", substr, flag->width, flag->precision, ft_strlen(substr));
	substr = ft_substr(string, 0, flag->precision);
	printf("** 3 Substr is %s, flag-width is %i, flag-precision is %i, strlen is %i **\n", substr, flag->width, flag->precision, ft_strlen(substr));
	substr = ft_flag_align(substr, flag, ' ');
	printf("** 4 Substr is %s **\n", substr);
	ft_putstr_fd(substr, 1);
	count = ft_strlen(substr);
	free(substr);
	return (count);
}
