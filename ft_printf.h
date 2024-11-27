/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:01:01 by oettaqi           #+#    #+#             */
/*   Updated: 2024/11/27 11:56:37 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_base(unsigned int nb);
int	ft_printf(const char *s, ...);
int	ft_putnbr_base_maj(unsigned int nb);
int	ft_print_ptr(void *ptr);
int	ft_putnbr_base_10(int nb);
int	ft_putnbr_base_10_un( unsigned int nb);

#endif