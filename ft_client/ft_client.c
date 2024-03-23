/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:39:40 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/23 00:15:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "ft_client.h"

void	fil_tab_len(int n, int depth, int tab[32])
{
	if (depth == 0) 
		return ;
	tab[depth - 1] = n % 2;
	fil_tab_len(n / 2, depth - 1, tab);
}

void	__send(int *tab, pid_t pid)
{
	int	i;
	int	kill_result;

	i = 0;
	while (i < 8)
	{
		if (tab[i] == 0)
		{
			kill_result = kill(pid, SIGUSR2);
			if (kill_result == -1)
				perror("Error sending SIGUSR2");
		}
		else if (tab[i] == 1)
		{
			kill_result = kill(pid, SIGUSR1);
			if (kill_result == -1)
				perror("Error sending SIGUSR1");
		}
		i++;
		usleep(200);
	}
}

void	send_bit(unsigned char octet, pid_t pid)
{
	unsigned char	n;
	int				tab[8];
	int				i;

	n = 128;
	i = 0;
	while (i < 8 && n != 0)
	{
		if ((octet - n) >= 0)
		{
			tab[i] = 1;
			octet -= n;
		}
		else
			tab[i] = 0;
		if (octet == 0 && n == 1)
			break ;
		n /= 2;
		i++;
	}
	i = 0;
	__send(tab, pid);
}

void	send_len(int tab[32], pid_t pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (tab[i] == 0)
			kill(pid, SIGUSR2);
		if (tab[i] == 1)
			kill(pid, SIGUSR1);
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		tab[32];
	pid_t	pid;
	int		i;
	int		len;

	pid = ft_atoi(argv[1]);
	if (pid > 1)
	{
		ft_printf("PID %d\n", pid);
		i = 0;
		ft_memset(tab, 1, 32);
		len = ft_strlen(argv[2]);
		ft_printf("Len : %d\n", len);
		fil_tab_len(len, 32, tab);
		send_len(tab, pid);
		while (argv[2][i])
			send_bit(argv[2][i++], pid);
		usleep(1000);
	}
	else
		write(1, "Don't play with me", 18);
}
