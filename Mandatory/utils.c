/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:49:37 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 20:42:53 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

void	__fil_len(int *signum, int *c, int *i)
{
	*c = *c << 1;
	if (*signum == SIGUSR1)
		*c = *c | 1;
	(*i)++;
}

void	__check_pid(int si_pid, int arr[3], int *c, char *ch)
{
	static int	pid_p1;
	static int	pid_p2;

	pid_p1 = si_pid;
	if (pid_p1 != pid_p2)
	{
		intializ_var(arr, c, ch, arr + 1);
		arr[2] = 0; 
		pid_p2 = pid_p1;
	}
}
