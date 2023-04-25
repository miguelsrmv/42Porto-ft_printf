/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:15:57 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/04/25 16:33:47 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct flags
{
	int		dot;	
	int		minus;	
	int		zero;	
	int		hashtag;
	int		space;
	int		plus;
	int		width;
	int		star;
	int		precision;
}	t_flags;

int				ft_printf(const char *string, ...);
t_flags			*newflag(void);
int				is_arg(char c);
void			ft_checkflag_values(char *string, int *i, t_flags *flag);
t_flags			*ft_checkflag(char *string, int *i);
int				ft_printf_char(char c, t_flags *flag);
int				ft_printf_string(char *string, t_flags *flag);
int				ft_printf_pointer(void *pointer, t_flags *flag);
int				ft_printf_int(int integer, t_flags *flag);
int				ft_printf_unsigned(unsigned int integer, t_flags *flag);
int				ft_printf_hexa(unsigned int integer, t_flags *flag);
int				ft_printf_hexa_upper(unsigned int integer, t_flags *flag);


#endif