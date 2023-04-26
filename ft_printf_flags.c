/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:14:09 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/26 19:29:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

t_flags	*newflag(void)
{
	t_flags	*flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag->dot = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->hashtag = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->width = 0;
	flag->precision = 0;
	return (flag);
}

int	is_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

void	ft_checkflag_values(char *string, int *i, t_flags *flag)
{
	if (flag->dot)
		flag->precision = ft_atoi(&string[*i]);
	else
		flag->width = ft_atoi(&string[*i]);
	while (ft_isdigit(string[*i]) == 1)
		(*i)++;
	(*i)--;
}

t_flags	*ft_checkflag(char *string, int *i)
{
	t_flags	*flag;
	flag = newflag();

	if (!flag)
		return (NULL);
	while (is_arg(string[++(*i)]) == 0)
	{
		if (string[*i] == '+')
			flag->plus = 1;
		else if (string[*i] == ' ')
			flag->space = 1;
		else if (string[*i] == '#')
			flag->hashtag = 1;
		else if (string[*i] == '-')
			flag->minus = 1;
		else if (string[*i] == '0')
			flag->zero = 1;
		else if (string[*i] == '.')
			flag->dot = 1;
		else if ((string[*i] >= '1' && string[*i] <= '9')
			&& (!flag->precision || !flag -> width))
			ft_checkflag_values(string, i, flag);
	}
	return (flag);
}
