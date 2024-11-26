/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:04:00 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/26 16:40:05 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

static int ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	if (s[0] == 0)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

// static int	handle(char c, va_list args)
// {
// 	int	nombre;

// 	nombre = 0;
// 	if (c == 'x')
// 		nombre = ft_putnbr_base(va_arg(args, unsigned int));
// 	else if (c == 'X')
// 		nombre = ft_putnbr_base_maj(va_arg(args, unsigned int));
// 	else if (c == 'p')
// 		nombre = ft_print_ptr(va_arg(args, void *));
// 	else if (c == 'c')
// 	{
// 		nombre = ft_putchar(va_arg(args, int));
// 		printf(" le  args est %c\n",va_arg(args, int));
// 	}
// 	// if (c == '%')
// 	// 	nombre = ft_putchar(va_arg(args, int));
// 	return (nombre);
// }

// int	ft_printf(const char *s, ...)
// {
// 	va_list	args;
// 	int	i;
// 	int	resu;

// 	i = 0;
// 	va_start(args, s);
// 	if (s == NULL)
// 		return (-1);
// 	resu = 0;
// 	while(s[i])
// 	{
// 		if (s[i] == '%')
// 		{
// 		 	// printf("le caractere qu'on passe a la fonction handle est %c\n",s[i + 1]);
// 			resu += handle(s[i + 1], args);
// 			i++;
// 		}
// 		else
// 			resu += ft_putchar(s[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return (resu);
// }

static int	handle(char c, va_list *args)
{
	int	nombre;

	nombre = 0;
	if (c == 'x')
		nombre = ft_putnbr_base(va_arg(*args, unsigned int));
	else if (c == 'X')
		nombre = ft_putnbr_base_maj(va_arg(*args, unsigned int));
	else if (c == 'p')
		nombre = ft_print_ptr(va_arg(*args, void *));
	else if (c == 'c')
		nombre = ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		nombre =  ft_putnbr_base_10(va_arg(*args, int));
	else if (c == '%')
		nombre = ft_putchar('%');
	else if (c == 'u')
		nombre =  ft_putnbr_base_10_un(va_arg(*args, int));
	else if (c == 's')
		nombre = ft_putstr(va_arg(*args, char *));
	return (nombre);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	resu;

	i = 0;
	va_start(args, s);
	if (s == NULL)
		return (-1);
	resu = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{
			resu += handle(s[i + 1], &args);
			i++;
		}
		else
			resu += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (resu);
}

// int main()
// {
// 	// ft_printf("%p", NULL);
// 	// printf("%c %c %c\n", '0', '1', '2');
// 	// ft_printf("%s", (char *)NULL);
// 	printf("%%\n");
// 	ft_printf("%%");
// 	// printf("%d",printf("%s", ""));

// 	// ft_printf("%c %c %c\n",'0', '1', '2');
// 	return (0);	
// }