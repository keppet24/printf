/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:38:49 by othmaneetta       #+#    #+#             */
/*   Updated: 2024/11/26 15:56:57 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base_10(int nb)
{
	int		n;
	long	l_nb;
	char 	*base;
	int		resu;

	resu = 0;
	base = "0123456789";
	n = ft_strlen(base);
	l_nb = nb;
	if (l_nb < 0)
	{
		l_nb = l_nb * (-1);
		resu += ft_putchar('-');
	}
	if (l_nb / n == 0)
		resu += ft_putchar(base[l_nb % n]);
	else
	{
		resu += ft_putnbr_base_10 (l_nb / n);
		resu += ft_putchar (base[(l_nb % n)]);
	}
	return (resu);
}

int	ft_putnbr_base_10_un( unsigned int nb)
{
	int		n;
	long	l_nb;
	char 	*base;
	int		resu;

	resu = 0;
	base = "0123456789";
	n = ft_strlen(base);
	l_nb = nb;
	if (l_nb < 0)
	{
		l_nb = l_nb * (-1);
		resu += ft_putchar('-');
	}
	if (l_nb / n == 0)
		resu += ft_putchar(base[l_nb % n]);
	else
	{
		resu += ft_putnbr_base_10_un (l_nb / n);
		resu += ft_putchar (base[(l_nb % n)]);
	}
	return (resu);
}