/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:22:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/25 15:12:22 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf_char(char c, t_flags *flag)
{
	free(flag);
	ft_putchar_fd(c, 1);
	return (1);
}
