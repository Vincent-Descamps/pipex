/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varhex_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:59:39 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/15 19:56:49 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_varhex_x(char format, unsigned int i)
{
	char		*base;
	int			j;

	j = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (i >= 16)
	{
		j += ft_varhex_x(format, i / 16);
		j += ft_varhex_x(format, i % 16);
	}
	if (i < 16)
		j += write(1, &base[i], 1);
	return (j);
}
