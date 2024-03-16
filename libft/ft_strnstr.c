/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:37:28 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/05 16:00:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelen;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0] && len - i >= needlelen 
			&& ft_strncmp(haystack + i, needle, needlelen) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
