/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:24:01 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/13 16:57:15 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	if (dst == src)
		return (dst);
	str = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dst);
}
