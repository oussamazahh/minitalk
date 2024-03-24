/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:41:01 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/24 00:43:49 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

char	*g_str;

void	intializ_var(int *i, int *c, char *ch, int *j)
{
	*c = 0;
	*i = 0;
	(void)ch;
	*j = 0;
	free(g_str);
	g_str = NULL;
}

void	print_str(int *signum, char *ch, int arr[3], int *c)
{
	*ch = *ch << 1;
	if (*signum == SIGUSR1)
		*ch = *ch | 1;
	(arr[1])++;
	if (arr[1] == 8)
	{
		g_str = add_char_to_string(g_str, *ch);
		arr[1] = 0;
		ch = 0;
		arr[0] = 33;
	}
	if ((int)ft_strlen(g_str) == *c)
	{
		ft_printf("STR : [%s]\n", g_str);
		kill(arr[2], SIGUSR1);
		intializ_var(arr, c, ch, arr + 1);
	}
}

void	__check_pid(int si_pid, int arr[2], int *c, char *ch)
{
	static int	pid_p1;
	static int	pid_p2;

	pid_p1 = si_pid;
	if (pid_p1 != pid_p2)
	{
		intializ_var(arr, c, ch, arr + 1);
		pid_p2 = pid_p1;
	}
}

void	mysignal_handler(int signum, siginfo_t *info, void *context)
{
	static int	arr[3];
	static int	c ;
	static char	ch;

	(void)context;
	__check_pid(info->si_pid, arr, &c, &ch);
	if (arr[0] < 32 && arr[1] == 0)
		__fil_len(&signum, &c, arr);
	if (arr[0] >= 32)
	{
		if (arr[1] == -1)
			arr[1] = 0;
		if (arr[0] == 32)
		{
			ft_printf("Len : [%d]\n", c);
			if (arr[1] == 0 && arr[0] == 32)
			{
				arr[1] = -1;
				arr[0]++;
			}
		}
		arr[2] = info->si_pid;
		if (arr[1] >= 0 && arr[0] > 32)
			print_str(&signum, &ch, arr, &c);
	}
}

int	main(int ar, char *av[])
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	(void )ar;
	(void )av;
	printf("The process ID is %d\n", pid);
	sa.sa_sigaction = mysignal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR2");
	while (1)
		pause();
	return (0);
}
