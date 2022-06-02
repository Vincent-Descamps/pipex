/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varint_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:16:02 by vdescamp          #+#    #+#             */
/*   Updated: 2021/11/15 18:49:37 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_varint_i(int i)
{
	long int	nb;
	int			j;

	j = 0;
	nb = i;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		j++;
	}
	if (nb >= 10)
	{
		j += ft_varint_i(nb / 10);
		j += ft_varint_i(nb % 10);
	}
	if (nb < 10)
	{
		nb = (nb % 10);
		nb = nb + '0';
		ft_putchar(nb);
		j++;
	}
	return (j);
}
/*
static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}*/
/*****************************/
	/*long int	nb;
	int			j;
	char		*num;

	nb = i;
	j = 0;
	num = ft_itoa(nb);
	ft_putstr(num);
	j = ft_strlen(num);
	free(num);
	return (j);*/
