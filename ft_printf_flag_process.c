/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:01:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 14:28:00 by mde-sa--         ###   ########.fr       */
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
	free(string);
	return (newstr);
}

char	*ft_flag_align(char *string, t_flags *flag, char c)
{
	char	*newstr;
	int		i;
/*
	printf("** 2 Substr is %s, flag-width is %i, flag-precision is %i, strlen is %i **", string, flag->width, flag->precision, ft_strlen(string));
	printf("##%i %i##", ft_strlen("(null)"), ft_strlen(string));
*/
	newstr = (char *)malloc(ft_strlen(string) + 1);
	if (!newstr)
		return (0);
	i = 0;
	if (flag->minus)
	{
		ft_strlcpy(newstr, string, ft_strlen(string) + 1);
		while (i < (int)(flag->width - ft_strlen(string)))
			newstr[ft_strlen(string) + i++] = c;
	}
	else
	{
		while (i < (int)(flag->width - ft_strlen(string)))
			newstr[i++] = c;
		ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	}
	free(string);
	return (newstr);
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
		(flag->precision) = (flag->precision) + 1;
	}
	else
		sign = '+';
	if (integer >= 0 && flag->plus)
		(flag->precision) = (flag->precision) + 1;
	i = 0;
	if (flag->plus || integer < 0)
		newstr[i++] = sign;
	while (i < (int)(flag->precision - ft_strlen(string)))
		newstr[i++] = '0';
	ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	free(string);
	return (newstr);
}

char	*ft_flag_hashtag(char *string)
{
	char	*newstr;
	int		i;
	int		index;

	index = 0;
	if (string[0] == '0')
		index++;
	if (string[1] == '0')
		index++;
	newstr = (char *)malloc(ft_strlen(&string[index]) + 1);
	if (!newstr)
		return (0);
	i = 0;
	newstr[i++] = '0';
	newstr[i++] = 'x';
	ft_strlcpy(&newstr[i], string, ft_strlen(string) + 1);
	free(string);
	return (newstr);
}
