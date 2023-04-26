/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/26 20:37:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	check_arg(char *string, int *i, va_list args)
{
	t_flags	*flag;
	int		counter;

	printf("##");
	flag = ft_checkflag(string, i);
	counter = 0;
	if (string[*i] == '%')
		counter += ft_printf_char('%', flag);
	else if (string[*i] == 'c')
		counter += ft_printf_char(va_arg(args, int), flag);
	else if (string[*i] == 's')
		counter += ft_printf_string(va_arg(args, char *), flag);
	else if (string[*i] == 'd' || string[*i] == 'i')
		counter += ft_printf_int(va_arg(args, int), flag);
	/*
	else if (*copy == 'u')
		*counter = printf_u(va_arg(args, unsigned int), counter);
	else if (*copy == 'x')
		*counter = printf_idx(va_arg(args, int), "0123456789abcdef", counter);
	else if (*copy == 'X')
		*counter = printf_idx(va_arg(args, int), "0123456789ABCDEF", counter);
	*/
	/*else if (*copy == p)
		*counter = ptf_ptr(va_arg(args, unsigned long), counter);*/
	return (counter);
}

int	ft_printf(const char *string, ...)
{
	int		counter;
	int		i;
	va_list	args;
	char	*str;

	str = (char *)string;
	counter = 0;
	i = 0;
	va_start(args, string);
	while (str[i])
	{
		if (str[i] == '%')
			counter += check_arg(str, &i, args);
		else
		{
			ft_putchar_fd(str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}