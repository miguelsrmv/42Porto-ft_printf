/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:22:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/28 09:01:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

char	*ft_itoa_base(long integer, char *base)
{
	char	*str;
	int		i;
	int		sign;

	if (integer == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (integer < 0)
	{
		sign = 1;
		integer *= -1;
	}
	i = 0;
	str = (char *)malloc((sizeof(char) * 32) + 1);
	if (!str)
		return (NULL);
	while (integer)
	{
		str[i++] = base[integer % (ft_strlen(base))];
		integer /= (ft_strlen(base));
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

int	ft_printf_base(int integer, char *base, t_flags *flag)
{
	char	*str;
	int		count;

	str = ft_itoa_base((long)integer, base);
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
	free(str);
	free(flag);
	return (count);
}
