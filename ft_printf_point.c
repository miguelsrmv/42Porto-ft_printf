/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:20:48 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 16:35:36 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_lutoa_base(long unsigned int address, char *base)
{
	char	*str;
	int		i;
	int		base_len;

	if (address == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	i = 0;
	str = (char *)malloc((sizeof(char) * 32) + 1);
	if (!str)
		return (NULL);
	while (address)
	{
		str[i++] = base[address % base_len];
		address /= base_len;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int	ft_printf_ptr(void *address)
{
	long unsigned int	cast_address;
	char				*str;

	if (!address)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	cast_address = (long unsigned int)address;
	str = ft_lutoa_base(cast_address, "0123456789abcdef");
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
