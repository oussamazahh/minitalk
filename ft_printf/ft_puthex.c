/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putheX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:15:50 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/10 15:08:30 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char c)
{
	char	*str;
	int		index;
	int		i;

	i = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	if (c == 'X')
		str = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_puthex(nb / 16, c);
	index = nb % 16;
	i += ft_putchar(str[index]);
	return (i);
}
