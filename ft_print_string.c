/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 17:28:01 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *string)
{
	char	*substr;
	int		count;

	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	substr = ft_substr(string, 0, ft_strlen(string));
	if (!substr)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(substr, 1);
	count = ft_strlen(substr);
	return (count);
}
