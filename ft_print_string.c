/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/25 17:15:16 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_string(char *string, t_flags *flag)
{
	char	*str;
	int		count;

	str = ft_strdup(string);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		free(flag);
		return (6);
	}
	count = ft_strlen(str);
	while (flag->width-- && flag->space)
		count += write(1, " ", 1);
	ft_putstr_fd(str, 1);
	free(flag);
	return (count);
}
