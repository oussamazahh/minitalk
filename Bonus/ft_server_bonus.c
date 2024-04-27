/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:41:01 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/27 21:13:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server_bonus.h"

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

void	__fill_str(int *i, int *c, char *ch)
{
	int	j;

	j = 0; 
	if (*i == 0)
	{
		g_str = (char *)malloc(*c * sizeof(char) + 1);
		if (!g_str)
		{
			intializ_var(i, c, ch, i);
			return ;
		}
		while (j < *c)
		{
			g_str[j] = '\0';
			j++;
		}
	}
	if (*i < *c)
		g_str[*i] = *ch;
	(*i)++;
	*ch = 0;
}

void	print_str(int *signum, char *ch, int arr[3], int *c)
{
	static int	i;
	static int	pid;

	if (i != 0 && pid != arr[2])
		i = 0;
	pid = arr[2];
	*ch = *ch << 1;
	if (*signum == SIGUSR1)
		*ch = *ch | 1;
	(arr[1])++;
	if (arr[1] == 8)
	{
		__fill_str(&i, c, ch);
		arr[1] = 0;
		arr[0] = 33;
	}
	if (i == *c)
	{
		ft_printf("%s\n", g_str);
		i = 0;
		kill(arr[2], SIGUSR1);
		intializ_var(arr, c, ch, arr + 1);
	}
}

void	mysignal_handler(int signum, siginfo_t *info, void *context)
{
	static int	arr[3];
	static int	c ;
	static char	ch;

	(void)context;
	arr[2] = info->si_pid;
	__check_pid(arr[2], arr, &c, &ch);
	if (arr[0] < 32 && arr[1] == 0)
		__fil_len(&signum, &c, arr);
	if (arr[0] >= 32)
	{
		if (arr[1] == -1)
			arr[1] = 0;
		if (arr[0] == 32)
		{
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

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("The process ID is %d\n", pid);
	sa.sa_sigaction = mysignal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error: cannot handle SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error: cannot handle SIGUSR2");
	while (1)
		pause();
	return (0);
}
