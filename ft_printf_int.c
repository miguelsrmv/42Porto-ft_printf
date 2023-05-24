/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:33:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/24 14:23:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int integer)
{
	char	*str;
	int		count;

	str = ft_itoa(integer);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	return (count);
}
