/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/20 23:53:57 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_server.h"
#include <string.h>
char *str;

char* add_char_to_string(char* str, char c)
{
    int len = ft_strlen(str);
    char* new_str = malloc((len + 2) * sizeof(char)); // Allocate memory for new string

    if (new_str == NULL) {
        return NULL; // Return NULL if memory allocation failed
    }

    ft_strlcpy(new_str, str,len); // Copy the original string to the new string
    new_str[len] = c; // Add the new character
    new_str[len + 1] = '\0'; // Add the null terminator

    return new_str;
}
void signal_handler(int signum, siginfo_t *info, void *context)
{
	static int i = 0;
	static int j = 0;
	static int c = 0;
	static int pid_p1;
	static int pid_p2;

    // 1100.0000
	(void)context;
	pid_p1 = info->si_pid;
	if (pid_p1 !=  pid_p2)
	{
		pid_p2 = pid_p1;
		c = 0;
		i = 0;
		j = 0;
	}
	if (i < 32)
	{
		c = c << 1;
		if (signum == SIGUSR1)
		{
			// ft_printf("1");
			c = c | 1;
		}
	// else if (signum == SIGUSR2)
	}
	i++;
	if (i == 32)
	{
		// ft_printf("0");
		ft_printf("Len : [%d]", c);
		c = 0;
		i = 0;
	}
	if (i >= 32)
	{
			c = c << 1;
			if (signum == SIGUSR1)
			{
				c = c | 1;
				ft_printf("1");
			}
			else
				ft_printf("0");
			// str = add_char_to_string(str, c);
			j++;
			if (j == 8)
			{
				ft_printf("khouna : [%c]", c);
				j = 0;
				c = 0;
			}
			i++;
	}
	usleep(400);
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
