/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/16 23:35:50 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
unsigned char c = 0;
// void print_bit(unsigned char octet)
// {
//   unsigned char n;

//   n = 128;
//   while (n != 0)
//   {
//     if ((octet - n) >= 0)
//     {
//       printf("1");
//       octet -= n;
//     }
//     else
//       printf("0");
//     if(octet == 0 && n == 1)
//       break;
//     n /= 2;
//   }
// }
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

void signal_handler(int signum) {
    printf("%u", c); 
    if (signum == SIGUSR1)
    {
        c = c << 1;
        write(1, "1", 1);
    }
    else if (signum == SIGUSR2)
    {
        c = c << 0;
        write(1, "0", 1);
    }
    // sleep(2);
}

int main()
{
    pid_t pid = getpid();
    printf("The process ID is %d\n", pid);

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    // Main loop
    while (1);
    return 0;//every time receives signal SIGUSR1 or SIGUSR2 and will print 1 or 2
}
// int main(void) {
//   pid_t pid;

//   pid = getpid();
//   printf("The process ID is %d\n", pid);
//   signal(SIGUSR1, signal_handler);
//   signal(SIGUSR2, signal_handler);
//   print_bit(255);
//   return 0;
// }