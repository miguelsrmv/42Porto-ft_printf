/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 13:36:13 by mde-sa--         ###   ########.fr       */
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
		substr = ft_substr("(null)", 0, flag->precision);
	else
		substr = ft_substr(string, 0, flag->precision);
	if (!substr)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	printf("String is %s", substr); /// SUBSTRING NAO ESTA DEFINIDA PQ??
	fflush(stdout);
	if (flag->precision == 0 && string)
		flag->precision = ft_strlen(string);
	substr = ft_substr(string, 0, flag->precision);
	substr = ft_flag_align(substr, flag, ' ');
	ft_putstr_fd(substr, 1);
	count = ft_strlen(substr);
	free(substr);
	return (count);
}
