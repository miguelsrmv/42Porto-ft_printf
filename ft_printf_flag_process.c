/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagprocess.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:01:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/27 00:20:50 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int	ft_flag_align(char *string, t_flags *flag)
{
	char	*newstr;
	int		i;
	int		count;

	newstr = (char *)malloc(ft_strlen(string) + 1);
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
	if (integer >= 0 && flag->plus)
		(int)(flag->precision)++;
	i = 0;
	if (flag->plus || integer < 0)
		newstr[i++] = sign;
	while (i < (int)(flag->precision - ft_strlen(string)))
		newstr[i++] = '0';
	ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	return (newstr);
}
