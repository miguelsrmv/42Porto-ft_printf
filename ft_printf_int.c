/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:33:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/25 16:41:49 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
	count = ft_strlen(str);
	while (flag->width-- + 1 && flag->space && integer >= 0)
		count += write(1, " ", 1);
	if (flag->plus && integer >= 0)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	free(flag);
	return (count);
}
