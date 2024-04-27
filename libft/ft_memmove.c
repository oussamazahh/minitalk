/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:37:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/19 13:50:02 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str2;

	str = (char *)src;
	str2 = (char *)dst;
	if (!len)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len)
		{
			len--;
			str2[len] = str[len];
		}
	}
	return (dst);
}
