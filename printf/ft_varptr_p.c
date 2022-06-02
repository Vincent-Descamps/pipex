/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:26:38 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/15 14:41:23 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_ptrlen(uintptr_t nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static void	ft_print_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_print_ptr(nb / 16);
		ft_print_ptr(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_varptr_p(unsigned long long ptr)
{
	int	j;

	j = 0;
	j += write(1, "0x", 2);
	if (ptr == 0)
		j += write(1, "0", 1);
	else
	{
		ft_print_ptr(ptr);
		j += ft_ptrlen(ptr);
	}
	return (j);
}
