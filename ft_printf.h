/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:01:01 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/25 18:21:32 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putnbr_base(unsigned int nb);
int	ft_printf(const char *s, ...);
int	ft_putnbr_base_maj(unsigned int nb);
int ft_print_ptr(void *ptr);


#endif