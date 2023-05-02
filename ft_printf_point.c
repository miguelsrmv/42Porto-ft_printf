/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:20:48 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 12:04:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*%#x*/

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

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

int	ft_printf_ptr(void *address, t_flags *flag)
{
	long unsigned int	cast_address;
	char				*str;

	cast_address = (long unsigned int)address;
	if (!address)
	{
		ft_putstr_fd("(nil)", 1);
		free(flag);
		return (5);
	}
	str = ft_lutoa_base(cast_address, "0123456789abcdef");
	if (!str)
	{
		free(flag);
		return (0);
	}
	if (!flag->width)
		flag->width = ft_strlen(str);
	if (flag->precision || flag->zero)
		str = ft_flag_padding(str, flag, 1);
	str = ft_flag_hashtag(str);
	str = ft_flag_align(str, flag, ' ');
	ft_putstr_fd(str, 1);
	free(flag);
	return (ft_strlen(str));
}
