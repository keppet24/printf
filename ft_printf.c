/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:04:00 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/25 18:49:08 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	handle(char c, va_list args)
{
	int	nombre;

	nombre = 0;
	if (c == 'x')
		nombre = ft_putnbr_base(va_arg(args, unsigned int));
	if (c == 'X')
		nombre = ft_putnbr_base_maj(va_arg(args, unsigned int));
	if (c == 'p')
		nombre = ft_print_ptr(va_arg(args, void *));
	return (nombre);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	resu;

	i = 0;
	if (s == NULL)
		return (-1);
	va_start(args, s);
	resu = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{
			resu += handle(s[i + 1], args);
			i++;
		}
		else
			resu += ft_putchar(s[i]);
		i++;
	}
	return (resu);
}

// int main()
// {
// 	ft_printf("%p", NULL);
// 	return (0);	
// }