/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:53:19 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/05 13:55:39 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			i;
	char		*str;

	num = n;
	str = (char *)malloc((count_num(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		num *= -1;
	if (n == 0)
		str[0] = '0';
	else
	{
		i = count_num(n) - 1;
		while (i >= 0 && num != 0)
		{
			str[i--] = (num % 10) + '0';
			num /= 10;
		}
		if (n < 0)
			str[i] = '-';
	}
	str[count_num(n)] = '\0';
	return (str);
}
