/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:33:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/28 09:04:04 by mde-sa--         ###   ########.fr       */
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
	if (flag->space && integer >= 0)
		str = ft_flag_space(str);
	if (!flag->width)
		flag->width = ft_strlen(str);
	if (flag->precision || flag->plus)
		str = ft_flag_padding(str, flag, integer);
	count = ft_flag_align(str, flag);
	free(flag);
	return (count);
}
