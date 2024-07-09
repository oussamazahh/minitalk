/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:06:08 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/08 17:26:27 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client_bonus.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Success√√√√\n");
		exit(0);
	}
}
