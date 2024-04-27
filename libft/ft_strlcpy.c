/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:56:47 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/04 13:24:45 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		if (dstsize > ft_strlen(src))
		{
			while (i < ft_strlen(src))
			{
				dst[i] = src[i];
				i++;
			}
		}
		else
		{
			while (i < dstsize - 1)
			{
				dst[i] = src[i];
				i++;
			}
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
