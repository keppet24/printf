/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:18:34 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/25 18:48:54 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_putnbr_base_ptr(unsigned long nb)
{
	int		n;
	unsigned long	l_nb;
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
		resu += ft_putnbr_base_ptr (l_nb / n);
		resu += ft_putchar (base[(l_nb % n)]);
	}
	return (resu);
}

int ft_print_ptr(void *ptr)
{
    int resu = 0;

    if (ptr == NULL)
        return (ft_putstr("(nil)"));
    resu += ft_putchar('0');
    resu += ft_putchar('x');
    resu += ft_putnbr_base_ptr((unsigned long)ptr);
    return resu;
}

// int main()
// {
// 	int a;
// 	a = printf("%p", NULL);
// 	printf("%d\n",a);
// 	printf("%d\n", ft_putstr("(nil)"));
// 	return (0);
// }