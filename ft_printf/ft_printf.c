/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:28:58 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/24 19:44:11 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	help(char c, va_list print)
{
	int	d;

	d = 0;
	if (c == 's')
		d += ft_putstr(va_arg(print, char *));
	else if (c == 'd' || c == 'i')
		d += ft_putnbr(va_arg(print, int));
	else if (c == 'c')
		d += ft_putchar(va_arg(print, int));
	else if (c == '%')
		d += ft_putchar('%');
	else if (c == 'u')
		d += ft_putu(va_arg(print, unsigned int));
	else if (c == 'p')
	{
		d += ft_putstr("0x");
		d += ft_putadd(va_arg(print, unsigned long));
	}
	else if (c == 'x')
		d += ft_puthex(va_arg(print, unsigned int), c);
	else if (c == 'X')
		d += ft_puthex(va_arg(print, unsigned int), c);
	return (d);
}

int	ft_printf(const char *format, ...)
{
	va_list	print;
	int		i;
	int		d;

	i = 0;
	d = 0;
	va_start(print, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			d += help(format[i], print);
		}
		else if (format[i] != '%')
			d += ft_putchar(format[i]);
		i++;
	}
	va_end(print);
	return (d);
}
