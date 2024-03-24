/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:49:37 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/23 14:24:28 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*add_char_to_string(char *str, char ch)
{
	int		length;
	char	*new_str;

	length = 0;
	if (str)
		length = ft_strlen(str);
	new_str = (char *)malloc((length + 2) * sizeof(char));
	if (new_str == NULL)
		return (str);
	if (str)
	{
		ft_strcpy(new_str, str);
		free(str);
	}
	new_str[length] = ch;
	new_str[length + 1] = '\0';
	return (new_str);
}

void	__fil_len(int *signum, int *c, int *i)
{
	*c = *c << 1;
	if (*signum == SIGUSR1)
		*c = *c | 1;
	(*i)++;
}
