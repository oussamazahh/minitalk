/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:58:19 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/05 15:42:03 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	j;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		f(i, &s[i]);
		i++;
	}
}
