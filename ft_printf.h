/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:15:57 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 18:19:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int				ft_printf(const char *string, ...);
int				ft_printf_char(char c);
int				ft_printf_string(char *string);
int				ft_printf_pointer(void *pointer);
int				ft_printf_int(int integer);
int				ft_printf_unsint(unsigned int unsigned_n);
int				ft_printf_base(int integer, char *base);
int				ft_printf_ptr(void *address);
int				ft_str_format(char *string);
char			*ft_utoa(unsigned int n);
char			*ft_itoa_base(unsigned int integer, char *base);
char			*ft_lutoa_base(long unsigned int address, char *base);
char			*ft_strrev(char *str);

#endif