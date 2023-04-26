/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:33:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/26 22:24:50 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	*ft_flag_space(char *string)
{
	char	*newstr;

	newstr = (char *)malloc(ft_strlen(string) + 1);
	if (!newstr)
		return (0);
	newstr[0] = ' ';
	ft_strlcpy(&newstr[1], string, ft_strlen(string) + 1);
	return (newstr);
}

int	ft_int_format(char *string, t_flags *flag)
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

char	*ft_flag_padding(char *string, t_flags *flag, int integer)
{
	char	*newstr;
	char	sign;
	int		i;

	newstr = (char *)malloc(ft_strlen(string) + 1);
	if (!newstr)
		return (0);
	if (integer < 0)
	{
		sign = '-';
		string = ft_substr(string, 1, ft_strlen(string));
		(int)(flag->precision)++;
	}
	else
		sign = '+';
	i = 0;
	if (flag->plus || integer < 0)
		newstr[i++] = sign;
	while (i < (int)(flag->precision - ft_strlen(string)))
		newstr[i++] = '0';
	ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	return (newstr);
}

int	ft_printf_int(int integer, t_flags *flag)
{
	char	*str;
	int		count;

	str = ft_itoa(integer);
	if (!str)
	{
		free(flag);
		return (0);
	}
	if (flag->space && integer >= 0)
		str = ft_flag_space(str);
	if (!flag->width)
		flag->width = ft_strlen(str);
	if (flag->precision || flag->plus)
		str = ft_flag_padding(str, flag, integer);
	count = ft_int_format(str, flag);
	free(flag);
	return (count);
}
