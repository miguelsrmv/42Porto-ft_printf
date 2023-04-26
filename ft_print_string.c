/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/26 19:08:27 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_str_format(char *string, t_flags *flag)
{
	char	*newstr;
	int		i;
	int		count;

	newstr = (char *)malloc(flag->width + 1);
	if (!newstr)
		return (0);
	i = 0;
	if (flag->minus)
	{
		ft_strlcpy(newstr, string, ft_strlen(string) + 1);
		while (i < (int)(flag->width - ft_strlen(string)))
			newstr[ft_strlen(string) + i++] = ' ';
	}
	else
	{

		while (i < (int)(flag->width - ft_strlen(string)))
			newstr[i++] = ' ';
		ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	}
	ft_putstr_fd(newstr, 1);
	count = ft_strlen(newstr);
	free(newstr);
	return (count);
}

int	ft_printf_string(char *string, t_flags *flag)
{
	char	*substr;
	int		count;

	if (!flag->precision)
		flag->precision = ft_strlen(string);
	substr = ft_substr(string, 0, flag->precision);
	if (!substr)
	{
		ft_putstr_fd("(null)", 1);
		free(flag);
		return (6);
	}
	count = ft_str_format(substr, flag);
	free(flag);
	return (count);
}
