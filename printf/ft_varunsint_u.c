/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varunsint_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:16:01 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/15 18:43:08 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_varunsint_u(unsigned int u)
{
	int	j;

	j = 0;
	if (u >= 10)
		j += ft_varunsint_u(u / 10);
	u = (u % 10) + '0';
	ft_putchar(u);
	j++;
	return (j);
}
