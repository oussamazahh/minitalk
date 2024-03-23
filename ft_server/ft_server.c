/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/23 00:55:16 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_server.h"
#include <string.h>

char	*str;

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*add_char_to_string(char* str, char ch)
{
	int		length;
	char	*new_str;

	length = 0;
	if (str)
		length = ft_strlen(str);
	new_str = (char *)malloc((length + 2) * sizeof(char)); // +2 for the new character and the null-terminating character
	if (new_str == NULL)
		return str;
	if (str)
	{
		ft_strcpy(new_str, str); // copy the original string to the new string
		free(str); // free the original string
	}
	new_str[length] = ch; // add the new character
	new_str[length + 1] = '\0'; // null-terminate the new string
	return new_str;
}

// void 		print_str(int signum, char *ch, int *j, int *i)
// {
// 	*ch = *ch << 1;
// 	if (signum == SIGUSR1)
// 	{
// 		*ch = *ch | 1;
// 		// ft_printf("1");
// 	}
// 	// else
// 	// 	ft_printf("0");
// 	j++;
// 	if (*j == 8)
// 	{
// 		// ft_printf("\n%c", ch);
// 		str = add_char_to_string(str, *ch);
// 		*j = 0;
// 		*ch = 0;
// 		*i = 33;
// 	}
// }

void signal_handler(int signum, siginfo_t *info, void *context)
{
	static long long int i;
	static int j;
	static int c ;
	static char ch;
	static int pid_p1;
	static int pid_p2;

	(void)context;
	pid_p1 = info->si_pid;
	if (pid_p1 !=  pid_p2)
	{
		pid_p2 = pid_p1;
		free(str);
		str = NULL;	
		c = 0;
		i = 0;
		j = 0;
	}
	if (i < 32 && j == 0)
	{
		c = c << 1;
		if (signum == SIGUSR1)
		{
			// ft_printf("1");
			c = c | 1;
		}
		i++;
	// else if (signum == SIGUSR2)
	}
	if (i >= 32)
	{
		if (j == -1)
			j = 0;
		// ft_printf("0");
		if (i == 32)
		{
			ft_printf("Len : [%d]\n", c);
			if (j == 0 && i == 32)
			{
				j = -1;
				i++;
			}
			// i++;
		}
		// c = 0;

		if (j >= 0 && i > 32)
		{
			// if (i == 33)
				// ft_printf("i >> = %d | j >>= %d\n",i, j);
				ch = ch << 1;
				if (signum == SIGUSR1)
				{
					ch = ch | 1;
					// ft_printf("1");
				}
				// else
				// 	ft_printf("0");
				j++;
				if (j == 8)
				{
					// ft_printf("\n%c", ch);
					str = add_char_to_string(str, ch);
					j = 0;
					ch = 0;
					i = 33;
				}
				if (ft_strlen(str) == c)
				{
					ft_printf("STR : [%s]", str);
					i = 0;
					j = 0;
					c = 0;
					ch = 0;
					free(str);
					str = NULL;
				}
		}
	}
	// usleep(500);
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
