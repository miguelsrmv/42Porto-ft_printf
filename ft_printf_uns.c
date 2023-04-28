/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:52:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/27 00:18:38 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_utoa(unsigned int n)
{
	char					*result;
	int						digit_length;
	unsigned int			n_copy;

	digit_length = 0;
	n_copy = n;
	while (n_copy != 0)
	{
		n_copy = n_copy / 10;
		digit_length++;
	}
	result = (char *)malloc(sizeof(char) * digit_length + 1);
	if (!result)
		return (NULL);
	result[digit_length] = '\0';
	while (digit_length)
	{
		result[digit_length - 1] = n % 10 + '0';
		n /= 10;
		digit_length--;
	}
	return (result);
}


int	ft_printf_unsint(unsigned int unsigned_n, t_flags *flag)
{
	char	*str;
	int		count;

	str = ft_utoa(unsigned_n);
	if (!str)
	{
		free(flag);
		return (0);
	}
	if (!flag->width)
		flag->width = ft_strlen(str);
	if (flag->plus)
		flag->plus = 0;
	if (flag->precision)
		str = ft_flag_padding(str, flag, 1);
	count = ft_flag_align(str, flag);
	free(flag);
	return (count);
}
