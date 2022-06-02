/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:13:40 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/15 19:51:16 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_check(char format, va_list ap);
int		ft_varchar_c(char c);
int		ft_varstr_s(char *str);
int		ft_varint_i(int i);
int		ft_varunsint_u(unsigned int u);
int		ft_varpercent(char c);
int		ft_varhex_x(char format, unsigned int i);
int		ft_varptr_p(unsigned long long ptr);

#endif
