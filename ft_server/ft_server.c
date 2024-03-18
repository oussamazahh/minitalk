/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:35:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/18 15:36:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_server.h"
 #include <string.h>

void print_bit(unsigned char octet)
{
  unsigned char n;
  unsigned char ch;

  n = 128;
  ch = 0;
  while (n != 0)
  {
    if ((octet - n) >= 0)
    {
      write(1, "1",1);
      octet -= n;
      ch += n;
    }
    else
        write(1, "0",1);
    if(octet == 0 && n == 1)
      break;
    n /= 2;
  }
}

void signal_handler(int signum) {
    static int i = 0;
    static int c = 0;
    // static int a;
    
    // if (i <= 7)
    // {
        c = c << 1;
        if (signum == SIGUSR1)
        {
          c = c | 1;
          // print_bit(c);
            // ft_printf("1");
            // usleep(42);
            // write(1, "1", 1);
        }
        else if (signum == SIGUSR2)
        {
          // print_bit(c);
            // ft_printf("0");
            // usleep(42);
            // write(1, "0", 1);
        }
        i++;
    // }
    if (i > 7)
    {
        ft_printf ("%c", c);
        c = 0;
        i = 0;
    }
    // ft_printf (" i >%d<\n", i);
}

int main()
{
    // pid_t pid = getpid();
    // printf("The process ID is %d\n", pid);

    // signal(SIGUSR1, signal_handler);
    // signal(SIGUSR2, signal_handler);
    pid_t pid = getpid();
    printf("The process ID is %d\n", pid);

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGUSR1");
    }

    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGUSR2");
    }
    while (1) ;
    // Main loop
    // pause();
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