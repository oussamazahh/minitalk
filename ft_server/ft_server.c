/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/19 21:39:48 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_server.h"
#include <string.h>

void signal_handler(int signum)
{
	static int i = 0;
	static int c = 0;

	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	usleep(200);
}

int main()
{
	struct sigaction sa;

	pid_t pid = getpid();
	printf("The process ID is %d\n", pid);
	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR1");

	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		perror("Error: cannot handle SIGUSR2");
	while (1)
		sleep(1);
	return 0;
}
