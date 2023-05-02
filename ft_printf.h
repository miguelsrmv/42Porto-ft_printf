/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:15:57 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/02 11:44:54 by mde-sa--         ###   ########.fr       */
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
int				ft_printf_unsint(unsigned int unsigned_n, t_flags *flag);
int				ft_printf_base(int integer, char *base, t_flags *flag);
int				ft_printf_ptr(void *address, t_flags *flag);
int				ft_str_format(char *string, t_flags *flag);
char			*ft_flag_padding(char *string, t_flags *flag, int integer);
char			*ft_flag_align(char *string, t_flags *flag, char c);
char			*ft_utoa(unsigned int n);
char			*ft_itoa_base(unsigned int integer, char *base);
char			*ft_lutoa_base(long unsigned int address, char *base);
char			*ft_flag_space(char *string);
char			*ft_strrev(char *str);
char			*ft_flag_hashtag(char *string);

#endif