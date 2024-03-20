/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/20 12:01:09 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_server.h"
#include <string.h>

void signal_handler(int signum, siginfo_t *info, void *context)
{
	static int i = 0;
	static int c = 0;
	static int pid_p1;
	static int pid_p2;

	c = c << 1;
	(void)context;
	pid_p1 = info->si_pid;
	if (pid_p1 !=  pid_p2)
	{
		pid_p2 = pid_p1;
		c = 0;
		i = 0;
	}
	if (signum == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		// if (c == '\0')
			// kill(pid_p1, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	usleep(100);
}

int main()
{
	struct sigaction sa;

	pid_t pid = getpid();
	printf("The process ID is %d\n", pid);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_RESTART;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR1");

	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR2");
	while (1);
	return 0;
}
