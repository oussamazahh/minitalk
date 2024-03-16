/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:59:33 by ozahidi           #+#    #+#             */
/*   Updated: 2023/12/26 18:27:20 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cel;

	if (!lst || !del)
		return ;
	while (*lst && lst)
	{
		cel = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cel;
	}
	*lst = NULL;
}
