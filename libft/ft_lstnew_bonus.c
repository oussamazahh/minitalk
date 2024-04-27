/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:57:50 by ozahidi           #+#    #+#             */
/*   Updated: 2024/01/05 15:40:23 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cel;

	cel = malloc(sizeof(t_list));
	if (!cel)
		return (NULL);
	cel->next = NULL;
	cel->content = content;
	return (cel);
}
