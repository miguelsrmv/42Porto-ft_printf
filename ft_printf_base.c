/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:22:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 12:53:20 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned int integer, char *base)
{
	char	*str;
	int		i;
	int		base_len;

	if (integer == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	i = 0;
	str = (char *)malloc((sizeof(char) * 32) + 1);
	if (!str)
		return (NULL);
	while (integer)
	{
		str[i++] = base[integer % base_len];
		integer /= base_len;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int	ft_printf_base(int integer, char *base, t_flags *flag)
{
	char	*str;
	int		count;
	char	c;

	str = ft_itoa_base((unsigned int)integer, base);
	if (!str)
	{
		free(flag);
		return (0);
	}
	if (!flag->width)
		flag->width = ft_strlen(str);
	if (flag->precision || flag->zero)
		str = ft_flag_padding(str, flag, integer);
	if (flag->hashtag && integer != 0)
		str = ft_flag_hashtag(str);
	if (flag ->zero)
		c = '0';
	else
		c = ' ';
	str = ft_flag_align(str, flag, c);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}
