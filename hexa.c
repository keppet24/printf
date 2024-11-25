/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:37:55 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/25 16:55:32 by oettaqi          ###   ########.fr       */
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

int	ft_putnbr_base(unsigned int nb)
{
	int		n;
	long	l_nb;
	char 	*base;
	int		resu;

	resu = 0;
	base = "0123456789abcdef";
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
		resu += ft_putnbr_base (l_nb / n);
		resu += ft_putchar (base[(l_nb % n)]);
	}
	return (resu);
}

int	ft_putnbr_base_maj(unsigned int nb)
{
	int		n;
	long	l_nb;
	char 	*base;
	int		resu;

	resu = 0;
	base = "0123456789ABCDEF";
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
		resu += ft_putnbr_base_maj (l_nb / n);
		resu += ft_putchar (base[(l_nb % n)]);
	}
	return (resu);
}

// int main()
// {
// 	int a;
// 	int b;
// 	a = ft_putnbr_base_maj(-9);
// 	write(1,"\n",1);
// 	printf("%d\n",a);
// 	b = ft_putnbr_base(-9);
// 	write(1,"\n",1);
// 	printf("%d\n",b);
// 	write(1,"\n",1);
// 	return (0);
// }
