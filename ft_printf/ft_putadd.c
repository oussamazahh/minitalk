/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:00:29 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/10 15:07:32 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long nb)
{
	const char	*str;
	int			index;
	int			i;
	int			j;

	i = 0;
	j = 0;
	str = "0123456789abcdef";
	if (nb >= 16)
		i += ft_putadd(nb / 16);
	index = nb % 16;
	i += ft_putchar(str[index]);
	return (i);
}
